#include "func_deformable_template.hpp"

#include <iostream>
int main(int argc, char* argv[]) {
  // printAgrs(1, 2, 4, 5, 3.15);
  // auto a = prinArgsRight(1, 2, 3, 4, 5);

  // std::tuple<int, double, float, int> t = std::make_tuple(1, 2.0, 3.0f, 4);

  // std::tuple<int, double, float, int> mytuple;
  // print(1, 2, 4, 5, 3.15);
  // printx(1, 2, 4, 5, 3.15);
  // expand1(1, 2, 4, 5, 6);
  // expand(1, 2, 4, 5, 6);
  // expand3(1, 2, 4, 5, 6,7);
  // expand4(1, 2, 4, 5, 6,7,9);

  int y = 4;
  printArgs(1, "Hello", 3.14, 'A');
  // auto lazyer1 = Lazy<int>(func,y);
  return 0;
}