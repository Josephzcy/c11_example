
#include <iostream>
#include <type_traits>
#include <string>
// todo：函数模板重载、
// 1. 函数模板入参限制

template<typename T,typename std::enable_if< std::is_integral<T>::value,int>::type = 0>
void printx(T t){
      std::cout << "Integral: " << t << std::endl;
}

template<typename T,typename std::enable_if<std::is_floating_point<T>::value,int>::type = 0>
void printx(T t){
   std::cout << "Floating point: " << t << std::endl;
}


// 2. 函数返回值重载
template<typename T>  // 不加typename，编译报错
typename std::enable_if<std::is_arithmetic<T>::value,std::string>::type to_string(T t){

  return t;
}
template<typename T>  // 不加typename，编译报错
typename std::enable_if<!std::is_arithmetic<T>::value,std::string>::type to_string(T t){
  return t;
}





// todo:类模板特化,返回值是void时，第二个参数不用显示写
template <typename T, typename Enable = void>
class MyClass;

template <typename T>
class MyClass<T, typename std::enable_if<std::is_integral<T>::value>::type> {
 public:
  void print() { std::cout << "template enable_if" << std::endl; }
};

template <typename T>
class MyClass<T, typename std::enable_if<std::is_floating_point<T>::value>::type> {
 public:
  void print() const { std::cout << "Floating point type" << std::endl; }
};
