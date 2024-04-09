#include "apply_deformatable_template.hpp"

#include <iostream>
int main(int argc, char *argv[]) {
  int y = 4;
  // auto lazyer1 = Lazy<int>(func, y);

  // auto a = RegisterLazy(func, y);
  // std::cout << a.Load() << std::endl;

  // Lazy<int> b = RegisterLazy([]{ return 12; });
  // std::cout << b.Load() << std::endl;

  std::function<int(int)> f = [](int x) { return x + 3; };
  auto c = RegisterLazy(f,10);
  std::cout << c.Load() << std::endl;


  return 0;
}