
#include "profile_optimise.hpp"
#include <iostream>
int main(int argc, char *argv[]) {
  // Myclass a = getA();
  // Myclass&& b(getA());
  std::vector<complex> v;
  v.reserve(10);
  std::cout << " capacity:" << v.capacity() << " size:" << v.size() << std::endl;

  v.emplace_back(1,2,3); // construct
    std::cout << " ==copy" << std::endl;

  v.emplace_back(complex(1, 2, 3));  // construct、copy ，没有临时对象

  std::cout << " ===copy" << std::endl;
  v.push_back(complex(2, 2, 3));  // consrtuct 、copy、
  return 0;
}