/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-07-31 19:06:31
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-07-31 19:08:18
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/subsrc/c++_example/before_main.hpp
 * @Description:
 */
/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-07-31 19:06:31
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-07-31 19:06:33
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/subsrc/c++_example/before_main.hpp
 * @Description:
 */

//! 全局对象的构造函数
/*
1.设置栈指针
2.初始化static静态和global全局变量，即data段的内容
3.将未初始化部分的赋初值：数值型short，int，long等为0，bool为FALSE，指针为NULL，等等，即.bss段的内容
4.将main函数的参数，argc，argv等传递给main函数，然后才真正运行main函数
*/

#include <stdio.h>

#include <iostream>
__attribute__((constructor)) void before_main() { printf("before main\n"); }
__attribute__((destructor)) void after_main() { printf("after main\n"); }
void function() { std::cout << "hello function" << std::endl; }

int f() {
  std::cout << "f" << std::endl;
  return 10;
}

class Obj {
 public:
  Obj() {
    // before_main();
    std::cout << "before_main obj" << std::endl;
  }

  ~Obj() {
    // after_main();
    std::cout << "after_main obj" << std::endl;
  }
};

class Base1 {
 public:
  Base1() { std::cout << "Base1" << std::endl; }
  ~Base1() { std::cout << "Base1" << std::endl; }
};

class Base2 {
 public:
  Base2() { std::cout << "Base2" << std::endl; }
  ~Base2() { std::cout << "Base2" << std::endl; }

 public:
  static Base1 m_base1;
};

//? 1. 全局对象的构造函数
Obj obj;

//? 2 全局变量、对象 和静态变量、对象的空间分配和赋初值
Base1 Base2::m_base1 = Base1();
//? 3.全局变量的赋值函数
int g_ = f();

//? 4 全局变量的调用
int a = []() {
  std::cout << "a" << std::endl;
  return 0;
}();

//! 静态变量初始化
//! 静态初始化
  //? zero 初始化 .bss 段
  //? const 初始化 .data 段
//! 动态初始化
 //? 全局静态变量或者类的静态成员变量 --- main() 函数之前
 //? 局部静态变量 --- main() 函数执行到相应的语句

//请注意，这个程序在调试的时候，如果类的成员变量采用静态初始化，根本无法进入类的静态成员变量初始化的那个断点，这是因为
//若采用静态初始化方式，类的静态成员是在程序加载时完成的初始化。

//静态初始化：是指用常量对变量进行初始化。其中未赋初值及初值为0的放在bss段，其他放在data段。静态初始化在程序加载时完成。
//动态初始化：是指需要经过函数调用才能完成的初始化，比如说：int a=foo()，或者复杂类型的初始化（需要调用构造函数）等。
//			  对于全局或者类的静态成员变量，是在main()函数执行前由运行时调用相应的代码进行初始化的。而对于局部静态变量，
//			  是在函数执行至此初始化语句时才开始执行的初始化。


// int s_iFirst;		
// int s_iSeond;

class CHaveStaticDataMemember
{
public:
	CHaveStaticDataMemember() { std::cout<<" CHaveStaticDataMemember construct ==="<<std::endl; };
	~CHaveStaticDataMemember() {std::cout<<" CHaveStaticDataMemember desconstruct ==="<<std::endl;};

private:
	static int m_iStaticInitial;
	static int m_iDynInitial;
};
