

// 功能：返回值类型
// 获取参数类型和个数的接口：sizeof ,std::tuple_element
// 1. 参数个数：sizeif(Ages...)
// 2. 获取参数类型接口：嵌套模板类

// todo::需要支持
// 1. 普通函数、函数指针
// 2. function
// 3. 函数对象，成员函数
// 实现思路：在基础模板的前提下，进行若干模板特化 ？ why

#include <functional>
#include <iostream>
#include <string>
#include <tuple>
class Test1 {
 public:
  Test1() = default;
  ~Test1() = default;
  int add(int a, int b) { return a + b; }
  void start() {
    // todo::decltype 作用于函数名，返回的是函数类型
    decltype(&Test1::add) func;
    func = &Test1::add;
    std::cout << " func(1, 2):" << (this->*func)(1, 2) << std::endl;
  }
};

// todo::申明一个模板特化需要一个基础模板,用模板特化类似于假重载
template <typename T>
struct FunctionTraits;

// todo::通用类型
template <typename Ret, typename... Args>
struct FunctionTraits<Ret(Args...)> {  // 模板类特化
 public:
  using FuncType = Ret(Args...);
  typedef Ret(FuncTypeC)(Args...);
  using RetType = Ret;

  typedef Ret (*Pointer)(Args...);

  using StlFunctionType = std::function<FuncType>;

  enum { arity = sizeof...(Args) };

  template <std::size_t I>
  struct args_type {
    static_assert(I < arity, "index out of range,index must less than sizeof Agrs");
    using type = typename std::tuple_element<I, std::tuple<Args...>>::type;
  };
};

// 2. 支持函数指针形式的调用
template <typename Ret, typename... Args>
struct FunctionTraits<Ret (*)(Args...)> : public FunctionTraits<Ret(Args...)> {};

// 3.支持function形式的调用
template <typename Ret, typename... Args>
struct FunctionTraits<std::function<Ret(Args...)>> : public FunctionTraits<Ret(Args...)> {};
// 4.支持成员函数的调用
#define FUNCTION_TRAITS(...)                                    \
  template <typename Ret, typename ClassType, typename... Args> \
  struct FunctionTraits<Ret (ClassType::*)(Args...) __VA_ARGS__> : public FunctionTraits<Ret(Args...)> {};

FUNCTION_TRAITS();
FUNCTION_TRAITS(const);
FUNCTION_TRAITS(volatile);
FUNCTION_TRAITS(const volatile);

// 5. 仿函数的调用decltype<&Class::operator>(Args...)
template <typename ClassType>
struct FunctionTraits : public FunctionTraits<decltype(&ClassType::operator())> {};

template <typename T>
void PrintType() {
  std::cout << "type:" << typeid(T).name() << std::endl;
}

using CastFunc = float(std::string, int);

std::function<int(int)> my_function = [](int a) { return a; };
int add(const int& a, const int& b) { return a + b; }
struct AA {
  void operator()() { std::cout << "AA operator function object" << std::endl; }
  void Print() { std::cout << "AA Print function..." << std::endl; }
};

class Test {
 public:
  Test() = default;
  ~Test() = default;
  void start() {
    // 1. function 、函数指针 、仿函数，普通函数

    PrintType<FunctionTraits<double(int, int)>::FuncTypeC>();
    PrintType<FunctionTraits<double(int, int)>::args_type<0>::type>();

    PrintType<FunctionTraits<decltype(my_function)>::FuncTypeC>();
    PrintType<FunctionTraits<decltype(my_function)>::args_type<0>::type>();

    PrintType<FunctionTraits<float (*)(std::string, int)>::FuncTypeC>();
    PrintType<FunctionTraits<float (*)(std::string, int)>::args_type<0>::type>();

    PrintType<FunctionTraits<AA>::RetType>();
    PrintType<FunctionTraits<AA>::FuncType>();

    using AAfunc = decltype(&AA::Print);
    PrintType<FunctionTraits<decltype(&AA::Print)>::RetType>();
    PrintType<FunctionTraits<AAfunc>::RetType>();

    PrintType<FunctionTraits<AA>::FuncType>();
  }
};

// todo::继承时基类成员函数的调用
// 1. 隐藏基类成员函数怎么调用 Base::function
// 2. 没有重写时基类成员函数的调用 d.BaseFuction
template <typename T>
class Base {
 public:
  void BaseFuction() { std::cout << "BaseFuction......" << std::endl; }
  void OverwriteBaseFuction() { std::cout << "OverwroteBaseFuction......" << std::endl; }
};

template <typename T>
class Derived : public Base<int> {
 public:
  void DerivedFuction() { std::cout << "DerivedFuction......" << std::endl; }
  void OverwriteDerivedFuction() { std::cout << "OverwroteDerivedFuction......" << std::endl; }
};
