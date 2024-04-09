/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-08-09 14:21:39
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-09 14:21:40
 * @fileName: Do not edit
 * @FilePath: /os_study/code_test/course1_test.cpp
 * @Description:
 */
#include "course1.hpp"

#include <stdio.h>
void swap(int* first, int* second) {
  int temp = *first;
  *first = *second;
  *second = temp;
}
int main(int argc, char** argv) {
  int a = 10;
  int b = 20;
  printf("a = %d; b = %d;\n", a, b);
  swap(&a, &b);
  printf("a = %d; b = %d;\n", a, b);
  return 0;
}