
// todo::类型推导

#include <iostream>
void GenericCodeTest() {
  //! auto 根据变量的初始化来推到变量类型
  //! decltype 编译器推到完后，并不会真正计算表达式的值

  int x = 0;
  decltype(x) y = 0;
  decltype(x + y) z = 0;
  const decltype(z)* p = &z;
  decltype(p)* pp = &p;  // pp ->int**

  std::cout << "pp :" << typeid(pp).name() << std::endl;
  std::cout << "y :" << typeid(y).name() << std::endl;
}

// todo! auto + decltype ,返回值后置
template <typename T, typename U>
auto add(T a, T b) -> decltype(a + b) {
  return a + b;
}

//! typename关键字在模板中还可以用于指定模板中的嵌套类型是一个类型名而不是成员变量或成员函数

class NestedType {};
template <typename T>
class MyClass1 {
 public:
  using NestedType = T;
};

template <typename T>
class MyClass {
 public:
  typename T::NestedType* ptr;  //  避免歧义
};

//! 模板 模板参数 需要用到class
template <template <class> class T>
void func1(T<int> a) {
  std::cout << "hello world:" << std::endl;
}

// 获取模板T类型的成员的相关类型
template <typename T>
class generic_code_test {
 private:
  /* data */
 public:
  generic_code_test(/* args */);
  ~generic_code_test();
};

#include <iostream>
int main(int argc, char* argv[]) {
  GenericCodeTest();

  MyClass<MyClass1<int>> a;

  return 0;
}