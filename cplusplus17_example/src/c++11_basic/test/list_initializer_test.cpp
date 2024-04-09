#include <iostream>

// 聚合类型
// 1. 无自定义构造函数
// 2. 无基类和虚函数
// 3. 无私有的或者保护的非静态成员

class Myclass {
 public:
  int a;
  float b;
  char c;
};

// 任意长度的初始化列表
class Myclass2 {
 public:
  Myclass2(std::initializer_list<int>);
};

// in_param
void func1(std::initializer_list<int> a) {
  for (auto i : a) {
    std::cout << i << std::endl;
  }
}
//todo::std::initializer_list<int> 存储的是引用，没有拷贝
std::initializer_list<int> func2() { return {1, 2, 3}; }

int main(int argc, char* argv[]) {
  Myclass temp{1, 2.0f, 'c'};

  func1({1, 3});
  func1({1, 3, 2});
  func2();
  return 0;
}