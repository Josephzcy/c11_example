/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-08-03 22:14:07
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-03 22:15:04
 * @fileName: Do not edit
 * @FilePath: /designer_pattters/subsrc/c++_example/template_declear.hpp
 * @Description:
 */

//! 为什么不能实现分离
//?1. 语言层面：C++规定：编译器在实例化模板时必须在上下文中可以查看到其定义实体如果只包含头文件，那就看不到定义实体，自然也就无法实例化模板了。
//?2. 编译层面：在看到实例化模板之前，编译器对模板的定义体是不处理的——原因很简单，编译器怎么会预先知道 typename 实参是什么呢？

//! 怎么解决实现分离的问题?
    //? .cpp 变成.inl 文件，实现声明和定义分离
#ifndef TEMPLATE_DECLEAR_HPP__
#define TEMPLATE_DECLEAR_HPP__
#include <iostream>
template <typename T>
class TemplateDeclear {
 public:
  TemplateDeclear(const int& a) {}
  ~TemplateDeclear() {}
  void add(const T& a, const T& b) {
    auto temp = a + b;
    std::cout << " a + b" << a + b << std::endl;
  }
};

class TemplateDeclear1 {
 public:
  TemplateDeclear1(const int& a) {}
  ~TemplateDeclear1() {}
  template <typename T>
  void add(const T& a, const T& b) {
    auto temp = a + b;
    std::cout << " a + b" << a + b << std::endl;
  }
  // void add(const T& a, const T& b);
};

#endif  //