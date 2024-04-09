#include "code_quality.hpp"

#include <iostream>
int main(int argc, char* argv[]) {
  test4();
  test5();
  // decltype(A()(11)) a = 1;  //没有默认构造函数，编译error

  decltype(std::declval<A>()(11)) a = 1;  // std::declval<A>() 获取A类型的临时对象


  std::cout << "a:" << a << std::endl;
  return 0;
}