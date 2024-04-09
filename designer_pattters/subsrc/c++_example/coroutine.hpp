/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-08-08 21:06:57
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-09 10:09:45
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/subsrc/c++_example/coroutine.hpp
 * @Description:
 */
/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-08-08 21:06:57
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-08 21:06:59
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/subsrc/c++_example/coroutine.hpp
 * @Description:
 */
#ifndef COROUTINE_HPP_
#define COROUTINE_HPP_
//! 协程：用户态的程序组件，非抢占式调度
  //? 协程的特点:自己的寄存器和上下文堆栈，可以在对个入口之间自由切换
  //? 协程的状态：libaco
    //! a. 运行态：运行中
    //! b. 挂起态： yiled 或者其他线程操作时进入挂起态
//! 协程实现：
  //? 协程控制块
  //? 写成创建：函数
  //? 携程切换
  //? 携程调度器
#endif