
#include "function_traits.hpp"
int main(int argc, char *argv[]) {
  float FreeFunc(const std::string &a, int b);

  PrintType<function_traits<decltype(FreeFunc)>::FuncType>();
  PrintType<function_traits<decltype(FreeFunc)>::ArgType<1>>();  // int
  // PrintType<function_traits<decltype(FreeFunc)>::arity>();  // int

  std::cout << "aa:" << function_traits<decltype(FreeFunc)>::arity << std::endl;  //2
  // ArgType<2>
  return 0;
}