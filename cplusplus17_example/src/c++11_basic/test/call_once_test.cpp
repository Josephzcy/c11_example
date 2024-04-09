
// #include "call_once.hpp"

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::once_flag flag;
int globalVariable;

void initializeGlobalVariable() { globalVariable = 42; }

// std::once_flag flag;
std::vector<int> sharedResource;

void initializeSharedResource() {
  // 初始化共享资源
  for (int i = 0; i < 10; ++i) {
    sharedResource.push_back(i);
  }
}

void useSharedResource() {
  std::call_once(flag, initializeSharedResource);

  // 使用sharedResource
  std::cout << "Shared resource size: " << sharedResource.size() << std::endl;
}

int main(int argc, char* argv[]) {
  // Singleton* singleton1 = Singleton::getInstance();
  // Singleton* singleton2 = Singleton::getInstance();
  // std::call_once(flag, initializeGlobalVariable);

  std::thread t1(useSharedResource);
  std::thread t2(useSharedResource);
  std::thread t3(useSharedResource);

  t1.join();
  t2.join();
  t3.join();

  return 0;
}

// #include <iostream>
// #include <mutex>
// #include <thread> // 添加这行

// std::once_flag flag;

// void initializeResource()
// {
//     std::cout << "Initializing resource" << std::endl;
//     // 在这里执行资源的初始化操作
// }

// void doSomething()
// {
//     std::call_once(flag, initializeResource);
//     // 在这里执行其他操作，确保initializeResource函数只被调用一次
// }

// int main()
// {
//     // 在多个线程中调用doSomething函数
//     std::thread t1(doSomething);
//     std::thread t2(doSomething);
//     std::thread t3(doSomething);
//     std::thread t4(doSomething);

//     t1.join();
//     t2.join();
//     t3.join();
//     t4.join();

//     return 0;
// }
