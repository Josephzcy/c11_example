/*** 
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-07-31 11:40:20
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-07-31 12:18:44
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/code_test/template_recusion_test.cpp
 * @Description: 
 */

#include <iostream>
#include"c++_example/template_recusion.hpp"
int main(int argc, char** argv) {
  auto res = sum(1, 1.1f, 1.100);
  std::cout << "res:"<<res << std::endl;
  return 0;
}