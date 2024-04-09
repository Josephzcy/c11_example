#include "singleton.hpp"
int main(int argc, char *argv[]) {
  Singleton<TestC>::getInstance(1,3.14);
  Singleton<TestC>::destroy();

  return 0;
}