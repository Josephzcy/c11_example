#include "function_traits.hpp"
int main(int argc, char *argv[]) {
  Test1 t1;
  t1.start();

  // 这就是给派生类使用的拓展api
  Derived<int> d;
  d.BaseFuction();
  d.Base::OverwriteBaseFuction();

  Test t;
  t.start();

  return 0;
}