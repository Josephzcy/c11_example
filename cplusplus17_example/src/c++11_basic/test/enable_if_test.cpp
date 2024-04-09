
#include "enable_if.hpp"
#include <iostream>
int main(int argc, char* argv[]) {
  MyClass<int> my_int;
  my_int.print();

  MyClass<float> myfloat;
  myfloat.print();

  printx(10);
  printx(3.14f);
  // print("hello");
  // std::cout << "a:" << a << std::endl;
  return 0;
}