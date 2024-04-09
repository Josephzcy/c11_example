/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-08-08 15:32:53
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-08 20:23:43
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/code_test/memory_order_test.cpp
 * @Description:
 */

#include "c++_example/memory_order.hpp"
int main(int argc, char** argv) {
  // IsLockFree();
  // default_aka_memory_order_seq_cst(); // 不会死循环
  memory_order_relaxed(); // 不会死循环，但是可能会很慢
  // increment_and_print_relaxed(); // 打印，不会死循环
  // memory_order_acquire_release(); // 第二个循环是死循环
  // memory_order_acquire_consume(); // 按理说不会死循环，但是gcc有bug
  // HighConcurrency();

  return 0;
}