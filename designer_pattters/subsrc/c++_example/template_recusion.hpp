/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-07-31 11:39:16
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-07-31 11:42:19
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/subsrc/c++_example/template_recusion.hpp
 * @Description:
 */


//! 重载+递归
template<typename T>
double sum(T a){
  return a;
}
template<typename T1, typename T2, typename... Args >
double sum(T1 a,T2 b,Args ...args){
  return a+b+sum(args...);
}

