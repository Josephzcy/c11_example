/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-08-03 19:32:51
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-04 10:19:31
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/subsrc/c++_example/constexpr.hpp
 * @Description:
 */

#include <array>
#include <iostream>

//! 常量表达式：指的是有一个或多个常量组成的表达式，不会改变并且在编译过程中就能得到计算结果的表达式
//! 字面值类型：算数类型(整型、浮点型)、引用、指针、字面值常亮类型、枚举

//! constexpr 和const的区别
//? 1.动态初始化：通过函数调用，间接初始化
//? 2.静态初始化 ：编译时初始化
//! 3. const 可以延迟到运行时初始化 ,constexpr 如果可以，在编译时期初始化，可以提高运行效率和减少内存占用(例如递归)
//! const 必须使用常量初始化

//! const 和constexpr 连用

//! constexpr 声明和初始化
//! constexpr 修饰变量，指针和引用
//! constexpr 修饰函数
//! constexpr 修饰类

int j = 0;
constexpr int i = 42;
void ConstexprInit() {
  //! constexpr 修饰指针或者引用：1. 必须初始化为nullptr 或者某个固定地址的值
  //? 1. 全局对象地址不变，2.函数中静态变量地址不变 3. 函数体内声明的变量地址一般是改变的
  //? constexpr 为顶层const,其指向的值可以改变。 左定值：指向的变量值；右定向：指向不能改变
  constexpr int *np = nullptr;
  constexpr int *np2 = &j;  //? 全局对象地址不变,但是值可以改变
  constexpr const int *np3 = &i;
  static int s_test = 0;
  constexpr int *constPtr = &s_test;
}

constexpr int RetConstexprFunc() { return 40; }
constexpr int RetArrSizeFunc(int i) { return i * RetConstexprFunc(); }
int g_i = 0;
//? error g_i 不是一个常量expression,&g_i 是一个常量expression
// constexpr int MyFunc() { return g_i; }
constexpr int MyFunc(int i) { return i; }

void ConstexprFuncTest() {
  //! constexpr函数指的是在编译的时候就能得到其返回值的函数,constexpr函数都是被隐式地定义为内联函数
  int arr[RetConstexprFunc()];
  int i = 3;
  int arr2[RetArrSizeFunc(i)];

  //? constexpr函数的形参可以是非常量，但是实参必须是常量,内联直接替换
  constexpr int tem = MyFunc(1) * 2;
  int arr3[MyFunc(i) * 2];

  // constexpr int tem1 = MyFunc(i) * 2; //? error
}

class ConstexprClass {
 public:
  constexpr ConstexprClass(int &value) : value_(value) {}
  int GetValue() const { return value_; }

 private:
  int value_;
};

int g_tempA = 4;
const int g_constTempA = 4;
constexpr int g_constExprTempA = 4;
void ConstexprPtrAndRef() {
  int tempA = 4;
  const int constTempA = 4;
  constexpr int constExprTempA = 4;

  /*1.正常运行,编译通过,指针的值为全局常量地址，其值是不变的*/
  const int *conptrA = &g_tempA;
  const int *conptrB = &g_constTempA;
  const int *conptrC = &g_constExprTempA;

  /*2.局部变量的地址要运行时才能确认，故不能在编译期决定，编译不过*/
  // constexpr int *conexprPtrA = &tempA;
  // constexpr int *conexprPtrB = &conTempA;
  // constexpr int *conexprPtrC = &conexprTempA;

  /*3.第一个通过，后面两个不过,因为constexpr int *所限定的是指针是常量，故不能将常量的地址赋给顶层const*/
  constexpr int *conexprPtrD = &g_tempA;
  // constexpr int *conexprPtrE = &g_constTempA;  //? g_constTempA和g_constExprTempA 是常量指针，不能指向int 的指针给它
  // constexpr int *conexprPtrF = &g_constExprTempA;

  /*4.局部变量的地址要运行时才能确认，故不能在编译期决定，编译不过*/
  // constexpr const int *conexprConPtrA = &tempA;
  // constexpr const int *conexprConPtrB = &conTempA;
  // constexpr const int *conexprConPtrC = &conexprTempA;

  /*5.正常运行，编译通过*/
  constexpr const int *conexprConPtrD = &g_constTempA;
  constexpr const int *conexprConPtrE = &g_constExprTempA;

  // todo::ref
  const int &conptr_refA = tempA;
  const int &conptr_refB = constTempA;
  const int &conptr_refC = constExprTempA;

  /*2.有两个问题：一是引用到局部变量，不能再编译器确定；二是conexprPtrB和conexprPtrC应该为constexpr
   * const类型，编译不过*/
  // constexpr int &conexpr_refA = tempA;
  // constexpr int &conexpr_refB = constTempA;    //? int 引用const 常量
  // constexpr int &conexpr_refC = constExprTempA;

  /*3.第一个编译通过，后两个不通过，原因是因为conexprPtrE和conexprPtrF应该为constexpr const类型*/
  constexpr int &conexpr_refD = g_tempA;
  // constexpr int &conexpr_refE = g_conTempA;
  // constexpr int &conexpr_refF = g_conexprTempA;

  // /*4.正常运行，编译通过*/
  constexpr const int &conexprCon_refD = g_tempA;
  constexpr const int &conexprCon_refE = g_constTempA;
  constexpr const int &conexprCon_refF = g_constExprTempA;
}

//? constexpr 修饰类的成员函数

#include <array>
template <typename T>
void show(T &&t) {
  // t.error();
  std::cout << "t.size:" << t.size() << std::endl;
}

class T {
 public:
  constexpr int getSize(int n) {
    int sum = 0;
    for (int i = 0; i <= n; i++) {
      sum += i;
    }
    return sum;
  }
};

//! constexpr 修饰自定义类型，对象在编译期间就已经初始化，2. constexpr 修饰构造函数并且函数体为空
//! 3. 且采用初始化列表初始化各成员时，必须使用裁量表达式
class ConstexprClass2 {
 public:
  constexpr ConstexprClass2(int value) : value_(value) {}
  constexpr int GetValue() const { return value_; }

 private:
  int value_;
};