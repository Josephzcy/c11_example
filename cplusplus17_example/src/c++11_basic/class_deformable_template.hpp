#include <iostream>
#include <tuple>
#include <type_traits>
#include <utility>


//todo::可变模板转化为 tuple + sequence + 折叠表达式 ，避免递归，推荐
template <typename... Args>
class VariadicTemplateClass {
 private:
  std::tuple<Args...> values;

 public:
  // 构造函数将参数包转发到tuple
  VariadicTemplateClass(Args... args) : values(std::forward<Args>(args)...) {}

  // 展开tuple并打印每个参数的辅助函数
  template <std::size_t... Is>
  void printHelper(std::index_sequence<Is...>) {
    // 使用折叠表达式打印每个参数
    (..., (std::cout << std::get<Is>(values) << std::endl));
  }

  // 打印所有参数的函数
  void printAll() { printHelper(std::make_index_sequence<sizeof...(Args)>()); }
};


// way5:可变参数模板类 + 特化模板类(前向声明)
template <typename First, typename... Args>
class Sum {
  enum { value = Sum<First>::value + Sum<Args...>::value };
};

// 特化
template <typename Last>
class Sum<Last> {
  enum { value = sizeof(Last) };
};


// todo::way6:递归继承
template <typename... Args>
class Base {};   // 前向申明

// 终止条件的特化
template <>
class Base<> {
 public:
  void print() { std::cout << "End of recursion" << std::endl; }
};

// 递归继承的特化
template <typename T, typename... Args>
class Base<T, Args...> : public Base<Args...> {
 public:
  void print() {
    std::cout << "Value: " << sizeof(T) << std::endl;
    Base<Args...>::print();
  }
};


// todo::way7:递归继承，推荐


// 递归继承的特化
template <typename First, typename... Args>
class MyBase : public MyBase<Args...> {
 public:
  void print() {
    std::cout << "Value: " << sizeof(First) << std::endl;
    MyBase<Args...>::print();
  }
};

// 终止条件的特化
template <typename Last>
class MyBase<Last> {
 public:
  void print() { std::cout << "End of recursion" << std::endl; }
};
