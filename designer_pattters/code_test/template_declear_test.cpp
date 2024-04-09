/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-08-03 20:55:47
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-03 20:55:47
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/code_test/template_declear_test.cpp
 * @Description:
 */

#include "c++_example/template_declear.hpp"
int main(int argc, char** argv) {
  int a = 3;
  // TemplateDeclear<int>* template_clear = new TemplateDeclear<int>(a);
  // template_clear->add(3,4);
  TemplateDeclear1* template_clear = new TemplateDeclear1(a);
  template_clear->add(3, 4);
  delete template_clear;
  return 0;
}
