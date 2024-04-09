#include "class_deformable_template.hpp"

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

  // Process<int, double, const char*> p(1, 3.14, "Hello");
  VariadicTemplateClass<int, double, const char*> obj(1, 3.14, "Hello, World!");
  obj.printAll();  // 打印所有存储在tuple中的值

  // ParamProcessor<int, double, const char*> processor;
  // processor.processParam(1);
  // processor.processParam(2.0);
  // processor.processParam("hello");

  // MyClass<int, double, std::string>::process();

  // processArgs<int, double, std::string>();
  // Base<int, float, double> obj1;
  // obj1.print();
  std::cout << "MyBase:==== " << std::endl;

  MyBase<int, float, double> obj1;
  obj1.print();

  return 0;
}