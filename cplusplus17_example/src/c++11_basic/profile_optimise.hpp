
// 万能引用，常量类型引用，const std::string&
// 未定义引用T&&,auto&&:只有发生自动类型推荐时，T 或 auto 才是未定义引用
// 右值引用：让临时变量重获新生，较少对象的拷贝和析构过程

#include <iostream>
#include <vector>
class Myclass {
 public:
  int construct_count{0};
  int move_count{0};
  int destruct_count{0};
  int copy_struct_count{0};

 public:
  Myclass() { std::cout << "construct_count:" << ++construct_count << std::endl; }
  Myclass(Myclass&&) { std::cout << "move_count:" << ++move_count << std::endl; }
  Myclass(const Myclass&) { std::cout << "copy_count" << ++copy_struct_count << std::endl; };
  ~Myclass() { std::cout << "destruct_count:" << ++destruct_count << std::endl; }
};

Myclass getA() { return Myclass(); }

//就地构造emplace 、enplace_back
class complex {
 public:
  complex(const int& year, const int& mounth, const int& day) : year(year), mounth(mounth), day(day) {
    std::cout << " construct" << std::endl;
  }
  complex(const complex& other) : year(other.year), mounth(other.mounth), day(std::move(other.day)) {
    std::cout << " copy" << std::endl;
  }

 private:
  int year;
  int mounth;
  int day;
};
