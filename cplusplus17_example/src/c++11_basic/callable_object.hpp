
#include <algorithm>
#include <functional>
#include <iostream>
#include <tuple>
#include <vector>
class callable {
 public:
  using FuncPtr = void (*)(void);
  int operator()(const int& a) {
    std::cout << "hello world" << std::endl;
    return a;
  }

  // todo::类对象转化为函数指针

  operator FuncPtr(void) {
    std::cout << "hello world FuncPtr" << std::endl;
    return print;
  }

  static void print() { std::cout << "hello world print " << std::endl; }
};

// todo::lamada 就地闭包,从此不要手写for循环
void test1() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6};

  int count = std::count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
}

// fuctional 回调，延迟调用
class MyClass1 {
 public:
  using CallBack = std::function<void()>;
  explicit MyClass1(const CallBack& callback) {
    std::cout << "hello world" << std::endl;
    callback_ = callback;
  }

  void notify() {
    if (callback_) {
      callback_();
    }
  }

 public:
  CallBack callback_;
};

// std::bind
// 1. callable 及其参数绑定成一个仿函数
// 2. 将n参数可绑定对象转化为n-1 可调用对象
void PrintValue(const int& a) { std::cout << "a:" << a << std::endl; }

auto f = std::bind(PrintValue, std::placeholders::_1);

void TestTuple() {
  // 替代结构体
  std::tuple<std::string, int> tp = std::make_tuple("hello", 100);
  std::string a1 = std::get<0>(tp);
  auto b1 = std::get<1>(tp);
  int a;
  std::string b;
  std::tie(b, std::ignore) = tp;

  std::tuple<int&&,std::string&&> tp1 = std::forward_as_tuple(100, "hello");
  auto [ c, d ] = tp;
  // auto tp1 = std::tie("hello", 100);  // tp :std::tuple<std::string&,int&>
}