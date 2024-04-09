
#include <iostream>
#include <type_traits>
// type_traits + 可变模板参数,编译期功能
class Base {};
class Derived : public Base {};

void test1() {
  // 类型判断traits
  std::cout << "const int:" << std::is_const<int>::value << std::endl;        // 0
  std::cout << "const int:" << std::is_const<const int>::value << std::endl;  // 1

  std::cout << std::is_same<int, int>::value << std::endl;              // 1
  std::cout << std::is_base_of<Base, Derived>::value << std::endl;      // 1
  std::cout << std::is_convertible<Derived, Base>::value << std::endl;  // 1
  std::cout << std::is_convertible<Base, Derived>::value << std::endl;  // 0
}

// type_convert traits,用模板参数创建对象时，要注意移除引用

template <typename T>
typename std::remove_reference<T>::Type* Create() {
  using MyType = typename std::remove_reference<T>::Type;  // typename 来告诉编译期这是个类型
  return new MyType();
}

void test2() {
  // 类型退化std::decay

  using A = std::decay<int&>::type;
  using B = std::decay<int&&>::type;

  using FuncPtr = std::decay<int(int)>::type;  // int (*)(int) ，函数指针

  std::cout << "const int:" << std::is_const<int>::value << std::endl;        // 0
  std::cout << "const int:" << std::is_const<const int>::value << std::endl;  // 1

  std::cout << std::is_same<int, int>::value << std::endl;              // 1
  std::cout << std::is_base_of<Base, Derived>::value << std::endl;      // 1
  std::cout << std::is_convertible<Derived, Base>::value << std::endl;  // 1
  std::cout << std::is_convertible<Base, Derived>::value << std::endl;  // 0
}

void test3() {
  // 根据条件选择类型

  using A = std::conditional<false, const int, int>::type;  // int
  using B = std::conditional<true, const int, int>::type;   // const int
}

// 获取可调用对象返回值类型：std::declval<A>(),获取任何类型的临时值，不管它是否有默认构造函数

template <typename F, typename Arg>
auto Func(F f, Arg arg) -> decltype(f(arg)) {
  return f(arg);
}

class A {
  A() = delete;

 public:
  int operator()(int i) { return i; }
};

int fn(int) { return int(); };

struct fn_class {
  int operator()(int i) { return i; }
};

void test4() {
  using fn_ref = int (&)(int);

  using fn_ptr = int (*)(int);

  using A = std::result_of<fn_ref(int)>::type;
  using B = std::result_of<fn_ptr(int)>::type;
  using C = std::result_of<fn_class(int)>::type;
  using D = std::result_of<decltype(fn)&(int)>::type;

  std::cout << std::is_same<A, int>::value << std::endl;  // 1
  std::cout << std::is_same<B, int>::value << std::endl;  // 1
  std::cout << std::is_same<C, int>::value << std::endl;  // 1
  std::cout << std::is_same<D, int>::value << std::endl;  // 1
};

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

decltype(add)& getFunction(bool useAddFunction) {
  if (useAddFunction) {
    return add;
  } else {
    return subtract;
  };
}
void test5() {
  // decltype(fn)&(int) 函数获取函数引用

  bool useAddFunction = true;

  // 根据 useAddFunction 的值选择要调用的函数
  auto& function = getFunction(useAddFunction);
  int result = function(5, 3);
  std::cout << "Result: " << result << std::endl;  //8 
}

