#include <iostream>
#include <string>
// 支持任意个参数、可变末班参数构造函数
template <typename T>
class Singleton {
 public:
  template <typename... Args>
  static T* getInstance(Args&&... args) {
    if (instance_ptr == nullptr) {
      instance_ptr = new T(std::forward<Args>(args)...);
    }
    return instance_ptr;
  }

  static void destroy() {
    delete instance_ptr;
    instance_ptr = nullptr;
  }

 private:
  Singleton(void);
  virtual ~Singleton(void) = default;
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
  Singleton(Singleton&&) = delete;
  Singleton& operator=(Singleton&&) = delete;

  static inline T* instance_ptr{nullptr};  //内联链接,c++17
};

class TestA {
  TestA(const std::string&) { std::cout << "lvalue" << std::endl; }

  TestA(std::string&&) { std::cout << "rvalue" << std::endl; }
};

class TestC {
 public:
  TestC(int x, double y) { std::cout << "Cvalue" << std::endl; }
};
