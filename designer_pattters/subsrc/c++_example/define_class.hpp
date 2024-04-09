/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-07-31 11:13:16
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-07-31 11:13:17
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/subsrc/c++_example/Base.hpp
 * @Description
 */
//! define 中 # para : 表示将para 转化为字符串; ##表示字符串链接
//! 1. 怎么注册：全局接口 new class_##para
//! 2. 注册到哪里去 map ，全局接口返回函数指针
//! 3. 使用 auto func = map[name]; func->print();
#pragma once
#include <iostream>
#include <map>
#include <memory>
class Base {
 private:
  /* data */
 public:
  Base(/* args */) {}
  ~Base() {}
  virtual void print() { std::cout << "this is Base print" << std::endl; }
  virtual void show() { std::cout << "this is Base show" << std::endl; }
};
class Derived : public Base {
 private:
  /* data */
 public:
  Derived(/* args */) {}
  ~Derived() {}
  virtual void print() override { std::cout << "this is Derived print" << std::endl; }
  void show() { std::cout << "this is Derived show" << std::endl; }
};

typedef std::shared_ptr<Base> (*CreatefeedFunction)();
typedef std::map<std::string, CreatefeedFunction> FuncMap;
FuncMap func_map;

#define REGISTER_CLASS(class_name)                                                 \
  \                                                                                                                                                               
namespace {                                                                        \
    std::shared_ptr<Base> Creator_##class_name() {                                 \
      \                     
      return std::shared_ptr<Base>(new class_name);                                \
    }                                                                              \
    class __Register_##class_name {                                                \
     public:                                                                       \
      __Register_##class_name() { func_map[#class_name] = &Creator_##class_name; } \
    };                                                                             \
    __Register_##class_name g_register_##class_name;                               \
  }
REGISTER_CLASS(Derived);
REGISTER_CLASS(Base);

int s_iFirst;		
int s_iSeond;