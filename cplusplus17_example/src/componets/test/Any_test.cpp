#include "Any.hpp"
int main(int argc, char *argv[]) {
  Any a;
  std::string str = "hello world";
  a = str;
  a.is<std::string>();
  a.AnyCast<std::string>();

  return 0;
}