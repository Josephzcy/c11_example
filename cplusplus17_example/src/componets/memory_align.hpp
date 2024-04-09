#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>
// Todo:: 委托构造：构造不同类型的参数;继承构造
// Todo::提高cpu读取内存数据的效率
// 知识点，数据类型对齐方式，数据类型大小
// 自定义类型对齐方式，最大成员对齐值的倍数
class MemoryAlign {
 public:
  struct MyStruct {
    char a;
    int b;
    short c;
    long long d;
    char e;
  };

  void test() {
    // 获取内存对齐的大小== 最大成员的对齐值
    std::cout << "Mystruct align size:" << alignof(MyStruct) << std::endl;  // 8
    std::cout << "Mystruct  size:" << sizeof(MyStruct) << std::endl;        // 32

    alignas(int) char c;
    std::cout << "c align size:" << alignof(c) << std::endl;  // 4

    // 编译器获取内存对齐大小
    std::cout << "Mystruct align size:" << std::alignment_of<MyStruct>::value << std::endl;  // 8

    // 终极目的：解决在指定内存上构造复合对象，内存对齐问题--> std::akign_storage()

    char c1[32];
    ::new (c1) MyStruct();  // 全局域作用运算符

    // 分配内存并指定大小内存对齐方式
    std::aligned_storage<sizeof(MyStruct), alignof(MyStruct)>::type xx;
    new (&xx) MyStruct();

    // 不那么重要，std::align,在指定缓冲区中找到符合条件的内存，成功返回true，失败返回false

    alignas(16) char buff[1024];
    void* pt = buff;
    std::size_t space_size = sizeof(buff);

    auto aligned_ptr = std::align(16, sizeof(MyStruct), pt, space_size);

    if (aligned_ptr) {
      std::cout << "Aligned pointer address: " << aligned_ptr << std::endl;
    } else {
      std::cout << "Alignment failed." << std::endl;
    }
  }
  void MeMoryAllocation() {
    // new = operator new + placement new
    // opetator new 语法：void* operator new(size_t size);需要配合void operator delete(void* ptr) noexcept;
    // palcement new 语法 new(ptr) T(initializer))
    void* ptr_memory = operator new(sizeof(MyStruct));

    //构造对象
    MyStruct* my_struct = new (ptr_memory) MyStruct();
    // 释放内存
    operator delete(ptr_memory);
  }
};

// c++11 新增有用的函数 ==> 函数式编程

class FuncProgram {
 public:
  void test() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 9, 8, 7};
    // std::copy_if(vec.begin(), vec.end(), vec.begin(), [](int x) { return x % 2 == 0; });

    std::cout << "is_sorted:" << std::is_sorted(vec.begin(), vec.end()) << std::endl;

    auto index = std::is_sorted_until(vec.begin(), vec.end());

    for (auto it = vec.begin(); it != index; it++) {
      std::cout << *it << std::endl;
    }

    auto a = std::minmax_element(vec.begin(), vec.end());  // 返回迭代器
    std::cout << "min:" << *a.first << " max:" << *a.second << std::endl;

    // 生成序列
    std::iota(vec.begin(), vec.end(), 2);
    for (const auto& i : vec) {
      std::cout << i << std::endl;
    }

    //查找
    std::find_if_not(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    std::any_of(vec.begin(), vec.end(), [](int x) { return x > 5; });
    std::none_of(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    std::all_of(vec.begin(), vec.end(), [](int x) { return x < 10; });
  }
};
