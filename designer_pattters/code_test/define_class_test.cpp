/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-07-31 11:13:34
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-07-31 11:18:42
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/code_test/define_class_test.cpp
 * @Description:
 */
/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-07-31 11:13:34
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-07-31 11:13:36
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/code_test/define_class_test.cpp
 * @Description:
 */
#include "c++_example/define_class.hpp"
int main(int argc, char** argv) {
  // auto ptrClass = func_map["Derived"];
  std::shared_ptr<Base> ptrClass = func_map["Derived"]();
  ptrClass->show();
  ptrClass->print();
  std::shared_ptr<Base> ptr = func_map["Base"]();
  // ptr->show();
  ptr->print();
  return 0;
}