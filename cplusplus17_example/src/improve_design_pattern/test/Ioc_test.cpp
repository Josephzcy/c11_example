

#include "Ioc.hpp"
int main(int argc, char *argv[]) {
  // Test t;
  // t.Test1();

  // Point p1(0, 0);
  // Point p2(3, 4);

  // 调用模板函数时通过尖括号指定其中一个自定义类型作为模板参数的部分类型
  // double dist = distance<Point>(p1, p2);
  // std::cout << "Distance: " << dist << std::endl;

  int a = 5;
  // todo:由于我们只指定了第一个模板参数为int，
  //编译器将使用这个指定调用函数参数类型来推断第二个模板参数的类型。在这个例子中，
  //第二个函数参数是double类型，
  //因此编译器会推断第二个模板参数U为double
  MyFunction<int>(a, 3.14);
  

  //todo::test
  IocTest ioc_test;
  ioc_test.start();
  return 0;
}
