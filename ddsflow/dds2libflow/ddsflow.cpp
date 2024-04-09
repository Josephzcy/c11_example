#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <fstream>
#include <streambuf>
#include <string>

#include "cJSON.h"
#include "dds_api.h"
#include "dds_common.h"
#include "flow.hpp"

using namespace minieye;

// @param topic: topic
// @param index: 内部数组的下标，array[index]
// @param ptr: 是指向当前元素的指针
// @param size: 当前元素的大小（字节）
// @param user: 用户数据
void onData(const char* topic, size_t index, void* ptr, size_t size,
            void* user) {
  printf("[topic: %s] array[%lu], size = %zu\n", topic, index, size);

  flow::Sender* sender = (flow::Sender*)user;
  sender->send(topic, (const char*)ptr, size);
}

void show_help(const char* pcName) {
  printf("usage: ./%s <config file>\n", pcName);
  exit(0);
}

int main(int argc, char** argv) {
  if (argc != 2) {
    show_help("ddsflow");
  }

  const char* pcConfigFile = argv[1];

  // read config.json
  std::ifstream fsConfig(pcConfigFile);
  std::string configJson((std::istreambuf_iterator<char>(fsConfig)),
                         std::istreambuf_iterator<char>());

  // Parse json
  cJSON* json = cJSON_Parse(configJson.c_str());
  printf("%s\n", cJSON_Print(json));

  // flow server address
  cJSON* poFlowAddr = cJSON_GetObjectItem(json, "flow_addr");
  if (poFlowAddr == nullptr) {
    printf("config file no `flow_addr` field.");
    exit(1);
  }
  char* pcFlowAddr = cJSON_GetStringValue(poFlowAddr);

  // flow server port number
  cJSON* poFlowPort = cJSON_GetObjectItem(json, "flow_port");
  if (poFlowPort == nullptr) {
    printf("config file no `flow_port` field.");
    exit(1);
  }
  int iFlowPort = (int)cJSON_GetNumberValue(poFlowPort);
  std::string sFlowPort = std::to_string(iFlowPort);

  // flow init
  flow::ctx0 = flow::Context({
      {"addr", pcFlowAddr},
      {"port", sFlowPort.c_str()},
  });

  if (flow::ctx0.start() != 0) {
    fprintf(stderr, "Error: cannot start flow context\n");
    exit(1);
  }

  flow::Sender sender(&flow::ctx0, "ddsflow sender");

  // dds init
  DDS::Context ctx(pcConfigFile, true);

  cJSON* poTopics = cJSON_GetObjectItem(json, "topics");
  int iTopicsNum = cJSON_GetArraySize(poTopics);
  for (int i = 0; i < iTopicsNum; i++) {
    cJSON* poOneTopic = cJSON_GetArrayItem(poTopics, i);
    cJSON* poOneTopicName = cJSON_GetObjectItem(poOneTopic, "topic");
    char* pcOneTopicName = cJSON_GetStringValue(poOneTopicName);
    DDS::Reader reader(&ctx, pcOneTopicName, onData, &sender);
  }

  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(1000));
  }

  return 0;
}
