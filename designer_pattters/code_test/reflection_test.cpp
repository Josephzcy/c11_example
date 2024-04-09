/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-07-31 11:18:26
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-03 10:01:44
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/code_test/reflection_test.cpp
 * @Description:
 */

#include "c++_example/reflection.hpp"
int main(int argc, char** argv) {
  dynamic_factory::IAbstractFactory* factory = dynamic_factory::IAbstractFactory::GetClassByName("C");
  auto class_name = factory->GetClassInfo()->GetClassName();

  dynamic_factory::IAbstractFactory* factoryD = dynamic_factory::IAbstractFactory::GetClassByName("D");
  auto class_namec = factory->GetClassInfo()->GetClassName();

  dynamic_factory::IAbstractFactory* factoryE = dynamic_factory::IAbstractFactory::GetClassByName("E");
  auto class_named = factory->GetClassInfo()->GetClassName();

  std::cout << "class_name:" << class_name << std::endl;
  std::cout << "class_name:" << class_namec << std::endl;

  std::cout << "class_name:" << class_named << std::endl;

  delete factory;
  delete factoryD;
  delete factoryE;

  return 0;
}