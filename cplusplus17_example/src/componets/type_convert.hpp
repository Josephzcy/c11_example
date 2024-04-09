#include <iostream>
#include <type_traits>

// dynamic_cast
// 1. 具有虚函数的类型结构
// 2. 基类指针和引用指向的实际类型是派生类的指针或者引用
// 3. 访问基类新增成员

// std::decay
// 1. 将给定类型转换为对应的 "decay" 类型
// 2. 即去除引用、去除顶层的 const/volatile 限定符;并将数组类型转换为指针类型。

class Base {
 public:
  Base() = default;
  ~Base() = default;

  virtual void func() { std::cout << "Base func...." << std::endl; }
};
class Derived : public Base {
 public:
  Derived() = default;
  ~Derived() = default;
  virtual void func() { std::cout << "Derived func...." << std::endl; }

 public:
  int val{10};
};

template <typename T>
void PrintType() {
  std::cout << "type:" << typeid(T).name() << std::endl;
}
class Test {
 public:
  Test() = default;
  ~Test() = default;

  void start() {
    Base* base_ptr = new Derived();
    Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);

    std::cout << "Derived val:" << derived_ptr->val << std::endl;  // 10" << std::endl;
    delete base_ptr;
    // delete derived_ptr;
  }
  void start2() {
    using T1 = std::decay<int&>::type;       // int
    using T2 = std::decay<int&&>::type;      // int
    using T3 = std::decay<int>::type;        // int
    using T4 = std::decay<const int>::type;  // int
    using T5 = std::decay<int[10]>::type;    // int*

    using T6 = std::decay<int (*)(int, int)>::type;  // 函数

    PrintType<T1>();
    PrintType<T2>();
    PrintType<T3>();
    PrintType<T4>();
    PrintType<T5>();
    PrintType<T6>();
  }
};