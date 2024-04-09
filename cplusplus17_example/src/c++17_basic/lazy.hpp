#ifndef LAZY_H_
#define LAZY_H_

#include <iostream>
#include <optional>
//todo::在用的时候初始化
class lazy {
 private:
  /* data */
 public:
  lazy(/* args */) = default;
  ~lazy() = default;

 public:
  std::optional<int> lazy_data = GetData() {
    std::cout << "" << std::endl;
    return 42;
  }
};

#endif