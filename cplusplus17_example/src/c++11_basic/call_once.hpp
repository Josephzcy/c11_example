#ifndef CallOnce_H_
#define CallOnce_H_
#include <iostream>
#include <mutex>
#include <thread>
// call_once 绑定一个函数对象，确保只会调用一次， todo:单例模式
//apply1:单例模式
class singleton {
 private:
  /* data */
  singleton(/* args */) = default;
  singleton &operator=(const singleton &) = delete;
  singleton(const singleton &) = delete;
  singleton &operator=(singleton &&) = delete;
  singleton(singleton &&) = delete;

  static inline singleton *singleton_ptr_{nullptr};  // c++17

 private:
  static inline std::once_flag call_once_flag_{};

 public:
  ~singleton() = default;

 public:
  static void print() { std::cout << "call once: " << std::endl; }
  static singleton *get_singleton() {
    std::cout << "call once 11" << std::endl;

    std::call_once(call_once_flag_, &singleton::print);
    std::call_once(call_once_flag_, []() {

      std::cout << "call once" << std::endl;
      singleton_ptr_ = new singleton();
    });
    return singleton_ptr_;
  }
};

//todo::全局变量初始化

std::once_flag flag;
int globalVariable;

void initializeGlobalVariable() {
    globalVariable = 42;
}






#endif