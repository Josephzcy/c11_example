#include <iostream>
#include <tuple>
#include <type_traits>
// 参数包展开：
// 1. 模板函数递归展开
// tuple+ std::enable_if +展开 + 函数模板
// 直接函数模板展开

// todo :: 把可变模板编程tuple 正常模板，然后再递归
template <std::size_t N = 0, typename Tuple>
inline typename std::enable_if<N == std::tuple_size<Tuple>::value, void>::type PrintTuple(Tuple t) {
  std::cout << "end ... " << std::endl;
}

template <std::size_t N = 0, typename Tuple>
    inline typename std::enable_if < N<std::tuple_size<Tuple>::value, void>::type PrintTuple(Tuple t) {
  //获取第N个元素 然后执行下一次递归

  if constexpr (std::is_same_v<std::tuple_element_t<N, Tuple>, int>) {
    std::cout << "Processing int: " << std::get<N>(t) << std::endl;
  }
  std::cout << "Processing : " << std::get<N>(t) << std::endl;
  PrintTuple<N + 1>(t);  //特化同时传一个
}

template <typename... Args>
void print(Args... args) {
  PrintTuple(std::make_tuple(args...));
}
// ---------------------------------------------

// todo:: 可变参数模板展开，递归+特化的方式
template <typename T>
void printx(T t) {
  std::cout << "recursion: " << t << std::endl;
}

template <typename T, typename... Args>
void printx(T t, Args... args) {
  std::cout << "recursion11: " << t << std::endl;
  printx(args...);
}
// ---------------------------------------------

// 4. 逗号表达式
template <typename... Args>
void expand1(Args... args) {
  std::initializer_list<int>{([&]() { std::cout << args << std::endl; }(), 0)...};
}
// template <typename... Args>
// void expand(Args... args) {
//   std::initializer_list<int>{([&]() { std::cout <<< args << std::endl; }(),...)};
// }

template <typename... Args>
void expand(Args... args) {
  ([&](const auto args) { std::cout << args << std::endl; }(args), ...);
}

// todo::折叠表达式 + lambda 对参数包展开，强烈推荐
template <typename... Args>  //折叠表达式
void expand3(Args... args) {
  (void([&]() { std::cout << args << std::endl; }()), ...);
}
// ---------------------------------------------

// todo::推荐使用
template <typename T>
void NormalPrint(const T& arg) {
  std::cout << "arg:" << arg << std::endl;
}

template <typename... Args>  //折叠表达式
void expand4(Args... args) {
  (NormalPrint(args), ...);
}
// ---------------------------------------------

// 2. 折叠表达式C++17,表达新式：(... 操作符 + args)
template <typename... Agrs>
void printAgrs(Agrs... args) {
  (std::cout << "agrs:" << ... << args) << std::endl;  /// 展开为：std::cout << arg1 << arg2 << arg3
}

template <typename... Args>
int prinArgsRight(int init, Args... args) {
  return (args + ... + init);  // 展开为：arg1 + arg2 + arg3 + init;
}

// todo::tuple 展开 c++17 constexpr
// 递归终止条件，当参数包为空时停止递归
template <typename... Args>
void printArgs(const Args... args) {
  std::cout << "args:" << std::endl;
}

// 递归遍历参数包，打印每个参数的值,模板特化
template <typename T, typename... Args>
void printArgs(const T& arg, const Args&... args) {
  std::cout << arg << " ";
  if constexpr (sizeof...(args) > 0) {
    printArgs(args...);  // 递归调用，继续遍历剩余的参数
  }
}
