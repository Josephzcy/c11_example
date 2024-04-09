#include <functional>
#include <mutex>
#include "flow.hpp"
#include <thread>
#include <iostream>
#include "vehicle_signal.pb.h"

class FlowRecv : public flow::Client {
 public:
  FlowRecv(const char* addr, const char* port, const char* topic,
           std::function<void(const char*, const char*, size_t)> callback)
      : flow::Client(
            flow::ClientConfig({"image",
                                std::string("ws://") + std::string(addr) +
                                    std::string(":") + std::string(port),
                                std::string(topic)})),
        FLowContext(
            flow::Config({{"servers", "none"}, {"sender.serialize", "none"}})),
        callback_(std::move(callback)) {
    FLowContext.add_client(this);
    if (FLowContext.start() != 0) {
      fprintf(stderr, "Error: cannot start flow context\n");
      exit(1);
    }
    fprintf(stderr, "  start flow context\n");
  }

  ~FlowRecv() { FLowContext.stop(); }

  virtual void recv(const char* source,  // '\0' terminated string
                    const char* topic,   // any binary data
                    const char* data,    // any binary data
                    size_t size) {
    std::lock_guard<std::mutex> lock(mutex_);
    this->callback_(topic, data, size);
  }

 private:
  flow::Context FLowContext;
  std::mutex mutex_;
  std::function<void(const char*, const char*, size_t)> callback_;
};

void recv_cb(const char* topic, const char* data, size_t size) {
    minieye::VehicleSignal vs;
    vs.ParseFromArray(data, size);
    std::cout << vs.signal_tm() << std::endl;
}

int main(int argc, char** argv) {
  FlowRecv* ptr = new FlowRecv(argv[1], argv[2], argv[3], &recv_cb);
  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(1000));
  }
  return 0;
}