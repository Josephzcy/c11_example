#include <iostream>
#include<string>
// todo::预处理宏，
//:1. 条件编译
//:2. 获取编译器或者操作系统相关的信息
// _func_, _FILE_, _LINE_
// _DATE_, _TIME_, _TIMESTAMP_
// _FUNCTION_、cplusplus

class PreprocossMacros {
 public:
  void Test(const std::string a ="test") {
    std::cout << "__FUNCTION__:" << __FUNCTION__ << std::endl;
    std::cout << "__PRETY_FUNCTION__:" << __PRETTY_FUNCTION__ << std::endl;


    std::cout << "__LINE__:" << __LINE__ << std::endl;
    std::cout << "__FILE__:" << __FILE__ << std::endl;

    std::cout << "__cplusplus:" << __cplusplus << std::endl;

    std::cout << "__STD_HOSTED__:" << __STDC_HOSTED__ << std::endl;
    // std::cout << "__STDCPP_THREADS__:" << __STDCPP_THREADS__ << std::endl;


  }
};