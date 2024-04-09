#include "callable_object.hpp"
int main(int argc, char* argv[]) {
  callable obj;
  // obj(21);
  // callable::FuncPtr a = obj();
  // a();
  obj();

  MyClass1 obj1([]() { std::cout << "hello world lamda" << std::endl; });
  f(100);
  obj1.notify();
  return 0;
}