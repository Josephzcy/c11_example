#include <functional>
#include <iostream>
#include <string>
class Myclass {
 public:
  void PrintMssage(const std::string& msg) { std::cout << msg << std::endl; }

  int add(int a, int b) { return a + b; }

 public:
  void test1() {
    // todo:function绑定成员函数指针,1.传对象引用，bind
    std::function<void(const std::string&)> myfunc = std::bind(&Myclass::PrintMssage, this, std::placeholders::_1);
    myfunc("hello");

    // todo::way2:像绑定静态成员函数一样绑定,传递this指针(对象引用)
    Myclass temp;
    std::function<void(Myclass&, const std::string&)> myfunc1 = &Myclass::PrintMssage;
    myfunc1(temp, "hello1");
  }

 public:
  void test2() { typedef int (Myclass::*FuncPtr)(int, int); 
    FuncPtr men_funptr = &Myclass::add;
  
  }
};