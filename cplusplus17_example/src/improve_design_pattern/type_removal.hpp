// c++ 类型擦除的方法
#include <algorithm>
#include <iostream>
#include <vector>
// 1. 多态擦除，强耦合
// 2. 通过模板来擦除，不同类型进行了抽象，但初始化时必须指定T的具体类型

// 3. c++17 联合体 std::variant
#include <variant>
void Test3() {
  // std::variant my_any;
  using PbType = std::variant<int, double, float>;
  std::vector<PbType> vec;
  vec.emplace_back(1);
  vec.emplace_back(2.0f);
  vec.emplace_back(3.0);

  std::for_each(vec.begin(), vec.end(), [](const auto& value) {
    std::visit([](const auto& val) { std::cout << "==== val:" << val << std::endl; }, value);
  });
}

// todo: 闭包来擦除
#include <functional>
// todo:: 无参通过lamada 来捕捉外面蚕食
template <typename T>
void PrintValue(const T& val) {
  std::cout << "val5:" << val << std::endl;
}

void Test5() {
  std::vector<std::function<void()>> vec;
  int x = 1;
  float y = 2.0f;
  double z = 3.0;
  std::string str("Hello world");

  vec.emplace_back([x] { PrintValue(x); });
  vec.emplace_back([y] { PrintValue(y); });
  vec.emplace_back([z] { PrintValue(z); });
  vec.emplace_back([str] { PrintValue(str); });

  for (const auto& item : vec) {
    item();
  }
}

// 4.通用类型插除，但是any 取数据需要知道类型
#include <any>

void TestAny() {
  std::any a = 1;
  std::any b = 1.25;
  std::any c = "string";

  std::vector<std::any> vec{a,b,c};
  // my_any.push_back();
}