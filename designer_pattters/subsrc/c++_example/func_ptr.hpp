/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-08-01 10:52:19
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-01 14:14:01
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/subsrc/c++_example/func_ptr.hpp
 * @Description:
 */

//*非静态要加一个类局限一下
//* 声明：1. typedef 返回值 (类名::*指针类型名)(参数列表); 2. typedef 返回值 (*指针类型名)(参数列表);
//* 赋值：指针类型名  指针名 = &类名::成员函数名
//* 使用：1. (类对象.*指针名)(参数列表); 2. (类指针->*指针名)(参数列表);

//? 函数指针的定义初始化
//? 函数指针的应用：回调
//? 函数指针在类中的使用
//! 如何初始化的问题
//! 1. 指向为类的成员变量
//! 2. 指向类的成员函数
//! 4. 函数指针在类外和类里面的区别
#include <iostream>
class funcPtr;  //? 前向声明
typedef void (funcPtr::*GFuncPtr)();
typedef void (*FuncPtrNormol)();

class funcPtr {
 public:
  typedef int (*StaticFuncPtr)();
  typedef int (funcPtr::*NoStaticFuncPtr)();  //? 需要加上域作用符限制一下

 public:
  StaticFuncPtr static_func_ptr{nullptr};
  NoStaticFuncPtr no_static_func_ptr{nullptr};
  static int StaticFunc() { std::cout << "static func member" << std::endl; }
  int NoStaticFunc() { std::cout << "no static func member" << std::endl; }

 public:
  void StartTest() {}

 private:
  /* data */
 public:
  funcPtr(/* args */) {
    static_func_ptr = &funcPtr::StaticFunc;  //? c++ 需要显示回去函数入口地址，即加上&
    no_static_func_ptr = &funcPtr::NoStaticFunc;
    static_func_ptr();
    (this->*no_static_func_ptr)();
  }
  ~funcPtr() {}
};
