

// todo:: 枚举类型 ，匿枚举类型，强枚举类型
#include <iostream>
enum { Red, Green, Blue };  //  里面的值可以直接拿过来使用

// 1. 可以隐式转化为int
// 2. 枚举值之间不存在命名空间，可能导致重复值，从而导致影长的bug
enum Day { Friday, WensDay, Tuesday, Monday };

// 推荐
// 1. 不能隐式转化为int
// 2. 枚举值之间具有独立的作用域，不会跟其他枚举值冲突
enum class Status { Init, Ready, Running, Stop, Release };

void Test() {
  int test_color = Red;
  Day day = Friday;
  Status current_status = Status::Ready;
}

// 应用场景
// 1. 标志位
// 2. 运行状态