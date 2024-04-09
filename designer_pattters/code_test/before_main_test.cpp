/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-07-31 19:06:45
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-07-31 19:07:07
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/code_test/before_main_test.cpp
 * @Description:
 */

#include "c++_example/before_main.hpp"




int DuplicateInt(int m)
{
  std::cout<<"2. DuplicateInt......."<<std::endl;
	return 2 * m;
}

//情况1：若类的静态成员变量采用静态初始化，是在加载时完成的，调试时无法跟踪到
//在main()函数执行前由运行时调用相应的代码进行初始化的
int CHaveStaticDataMemember::m_iStaticInitial = 3;				

//情况2：若类的静态成员变量采用动态初始化，是由运行时调用的，调试时可以跟踪到
//在main()函数执行前由运行时调用相应的代码进行初始化的
int CHaveStaticDataMemember::m_iDynInitial = DuplicateInt(3);	

/*	特殊情况：如果说没有头文件中的变量声明，此处是无法编译通过的。
	对于出现在同一个编译单元内的全局变量来说，它们初始化的顺序与他们声明的顺序是一致的（销毁的顺序则反过来），
	而对于不同编译单元间的全局变量，c++ 标准并没有明确规定它们之间的初始化（销毁）顺序应该怎样
*/
// int s_iSeond = 5 * s_iFirst;	//由于在头文件中提前声明了s_iFirst和s_iSeond，所以编译时就按照这个顺序进行初始化
// int s_iFirst = 5;

//情况3：全局变量和类的静态成员变量一样，如果采用静态初始化，是在加载的时候完成的初始化，调试时无法跟踪到
//在main()函数执行前由运行时调用相应的代码进行初始化的
int s_iGlobalStatic = 8*2;

//情况4：全局变量和类的静态成员变量一样，如果采用动态初始化，是由运行时调用的，调试时可以跟踪到
//在main()函数执行前由运行时调用相应的代码进行初始化的
int s_iGlobalDyn = DuplicateInt(8);

void GetSome()
{
	//情况5：局部静态变量和静态成员变量一样，如果采用静态初始化，是在加载的时候完成的初始化，调试时无法跟踪到
	//在main()函数执行前由运行时调用相应的代码进行初始化的
	static int s_GlobalInfun = 7;
	std::cout << "now in GetSome fun" << s_GlobalInfun << std::endl;
}

int main()
{
	//! *情况5：局部静态变量和静态成员变量一样，如果采用静态初始化，是在加载的时候完成的初始化，调试时无法跟踪到
	//在main()函数执行前由运行时调用相应的代码进行初始化的
	static int iLocalStatic = 3;

	//! *情况6：局部静态变量采用动态初始化，是函数执行至此语句完成初始化的，调试时可以跟踪到
	static int iLocalDyn = DuplicateInt(3);

	std::cout << "now in main fun" << std::endl;
	std::cout << iLocalStatic << std::endl;

	GetSome();
	return 0;
}

