/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-08-03 19:33:10
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-04 10:55:32
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/code_test/constexpr_test.cpp
 * @Description:
 */

#include "c++_example/constexpr.hpp"
int main(int argc, char** argv) {
  ConstexprInit();
  ConstexprFuncTest();

  int value = 5;
  ConstexprClass constexpr_class(value);

  // constexpr constexpr_class1(value);

  int arr[constexpr_class.GetValue()];
  // int arr1[constexpr_class1.GetValue()];
  constexpr int len = 5;
  std::array<int, len> a;
  std::array<int, T().getSize(len)> b;
  show(b);

  constexpr ConstexprClass2 constexpr_class2(10);
  auto temp =constexpr_class2.GetValue();
  std::cout<<"temp:"<<temp<<std::endl;
  return 0;
}