#include "message_bus.hpp"
int main(int argc, char *argv[]) {
  std::cout << "message bus example" << std::endl;

  Test t;
  t.start();
  return 0;
}