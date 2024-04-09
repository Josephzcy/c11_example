#include "dds_api.h"
#include "dds_common.h"
#include "vehicle_signal.pb.h"
#include "common/memory/mempool.h"

using namespace minieye;
int main(int argc, char** argv) {
  const char* pcConfigFile = argv[1];
  DDS::Context ctx(pcConfigFile, true);
  DDS::Writer writer(&ctx, argv[2]);
  minieye::VehicleSignal vs;
  int i = 1;
  void* msg;
  int sz = 10000;
  while (true) {
    std::cout << "pub: " << i << std::endl;
    vs.set_signal_tm(i++);
    vs.SerializeToArray(msg, vs.ByteSizeLong());
    writer.Write(msg, vs.ByteSizeLong());
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}