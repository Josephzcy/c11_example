/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-08-08 15:32:41
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-08 15:34:05
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/subsrc/c++_example/memory_order.hpp
 * @Description:
 */
#ifndef MEMORY_ORDER_
#define MEMORY_ORDER_

//! atomic 原子操作：保证指令的执行能正常执行完，不会被中断(内存到CPU、CPU运算、运算结果到内存)
//! 并发的时候，编译器和CPU对指令进行重排
//! 同步的粒度，内存序列
/*
typedef enum memory_order {
    memory_order_relaxed,
    memory_order_consume,
    memory_order_acquire,
    memory_order_release,
    memory_order_acq_rel,
    memory_order_seq_cst
} memory_order;
*/
#include <assert.h>

#include <atomic>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <set>
#include <thread>
#include <utility>
#include <vector>

std::atomic<int> x, y;
std::set<std::pair<int, int>> xy_set;
std::atomic<int> a(0), b(0), c(0);  // 1
std::atomic<bool> go(false);        // 2

void print_set(std::set<std::pair<int, int>>& set) {
  for (const auto& s : set) {
    std::cout << "(" << s.first << ", " << s.second << "), ";
  }
  std::cout << std::endl;
}

void default_aka_memory_order_seq_cst() {
  // 可能的输出(0,0), (1, 0), (0, 2), (1, 2)
  xy_set.clear();
  while (xy_set.size() != 4) {
    x = y = 0;
    go = false;
    std::thread t1([]() {
      while (!go)
        ;
      x.store(1);
    });
    std::thread t2([]() {
      while (!go)
        ;
      y.store(2);
    });
    std::thread t3([]() {
      while (!go)
        ;
      int tmp_x = x.load();
      int tmp_y = y.load();
      xy_set.emplace(std::pair<int, int>(tmp_x, tmp_y));
      // std::cout << tmp_x << ", " << tmp_x << std::endl;
    });
    go = true;
    t1.join();
    t2.join();
    t3.join();
  }

  print_set(xy_set);

  std::cout << "-----------------" << std::endl;

  x = y = 0;
  xy_set.clear();
  // 可能的输出(0,0), (1, 0), (1, 2)
  // 电脑有点太快了，添加nanoseconds后可能出现(1,0)，不加的话(0,0), (1, 0), (1, 2)都可能出来
  while (xy_set.size() != 3) {
    x = y = 0;
    go = false;
    std::thread t1([]() {
      while (!go)
        ;
      x.store(1);
      y.store(2);
    });
    std::thread t2([]() {
      while (!go)
        ;
      int tmp_x = x.load();
      int tmp_y = y.load();
      xy_set.emplace(std::pair<int, int>(tmp_x, tmp_y));
    });
    go = true;
    t1.join();
    t2.join();
  }
  print_set(xy_set);
}
//! memory_order_release/memory_order_acquire :写之后、读之前 (可见的)
//! memory_order_release/memory_order_consume ：只阻止对这个原子量有依赖的操作重拍到前面去
void memory_order_relaxed() {
  xy_set.clear();
  // 可能的输出(0,0), (1, 0), (0, 2), (1, 2)
  while (xy_set.size() != 4) {
    x = y = 0;
    go = false;
    std::thread t1([]() {
      while (!go)
        ;
      x.store(1, std::memory_order_relaxed);
    });
    std::thread t2([]() {
      while (!go)
        ;
      y.store(2, std::memory_order_relaxed);
    });
    std::thread t3([]() {
      while (!go)
        ;
      int tmp_x = x.load(std::memory_order_relaxed);
      int tmp_y = y.load(std::memory_order_relaxed);
      xy_set.emplace(std::pair<int, int>(tmp_x, tmp_y));
    });
    go = true;
    t1.join();
    t2.join();
    t3.join();
  }
  print_set(xy_set);

  std::cout << "-----------------" << std::endl;
  x = y = 0;
  xy_set.clear();
  // 可能的输出(0,0), (1, 0), (1, 2), 同时也有(0, 2)
  while (xy_set.size() != 4) {
    x = y = 0;
    go = false;
    std::thread t1([]() {
      while (!go)
        ;
      x.store(1, std::memory_order_relaxed);
      y.store(2, std::memory_order_relaxed);
    });
    std::thread t2([]() {
      while (!go)
        ;
      int tmp_x = x.load(std::memory_order_relaxed);
      int tmp_y = y.load(std::memory_order_relaxed);
      xy_set.emplace(std::pair<int, int>(tmp_x, tmp_y));
    });
    go = true;
    t1.join();
    t2.join();
  }
  print_set(xy_set);
  xy_set.clear();
}

void memory_order_acquire_release() {
  xy_set.clear();
  int tmp_y = 0;
  int cnt = 0;
  // 可能的输出(0,0), (1, 0), (0, 2), (1, 2)
  do {
    x = y = 0;
    go = false;
    std::thread t1([]() {
      while (!go)
        ;
      x.store(1, std::memory_order_release);
    });
    std::thread t2([]() {
      while (!go)
        ;
      y.store(2, std::memory_order_release);
    });
    std::thread t3([&tmp_y]() {
      while (!go)
        ;
      while (!(x.load(std::memory_order_acquire) == 1))
        ;
      int tmp_x = x.load(std::memory_order_acquire);
      tmp_y = y.load(std::memory_order_acquire);
      xy_set.emplace(std::pair<int, int>(tmp_x, tmp_y));
    });
    go = true;
    t1.join();
    t2.join();
    t3.join();
    ++cnt;
  } while (tmp_y == 2);
  std::cout << cnt << std::endl;
  print_set(xy_set);

  std::cout << "-----------------" << std::endl;
  // 语序的原因，一定死循环
  x = y = 0;
  xy_set.clear();
  tmp_y = 0;
  do {
    x = y = 0;
    go = false;
    std::thread t1([]() {
      while (!go)
        ;
      y.store(2, std::memory_order_relaxed);
      x.store(1, std::memory_order_release);
    });
    std::thread t2([&tmp_y]() {
      while (!go)
        ;
      while (!(x.load(std::memory_order_acquire) == 1))
        ;
      int tmp_x = x.load(std::memory_order_acquire);
      tmp_y = y.load(std::memory_order_acquire);
      xy_set.emplace(std::pair<int, int>(tmp_x, tmp_y));
    });
    go = true;
    t1.join();
    t2.join();
  } while (tmp_y == 2);
  print_set(xy_set);
  xy_set.clear();
}

template <typename T>
void PrintIsLockFree(const T& t) {
  std::cout << t.is_lock_free() << std::endl;
}
void IsLockFree() {
  PrintIsLockFree(x);
  PrintIsLockFree(y);
  PrintIsLockFree(go);
  struct Minieye {
    /* data */
  };
  std::atomic<Minieye> minieye;
  PrintIsLockFree(minieye);

  // 这里很搞笑，cpp_reference里头显示非lock_free，但是我都扩大a很多了显示lock_free，具体也的确和编译器有关
  struct BigMinieye {
    double a[1];
  };
  std::atomic<Minieye> big_minieye;
  PrintIsLockFree(big_minieye);
}

unsigned const loop_count = 10;

struct read_values {
  int a, b, c;
};

read_values values1[loop_count];
read_values values2[loop_count];
read_values values3[loop_count];
read_values values4[loop_count];
read_values values5[loop_count];

void increment_relaxed(std::atomic<int>* var_to_inc, read_values* values) {
  while (!go) std::this_thread::yield();  // 3 自旋，等待信号
  for (unsigned i = 0; i < loop_count; ++i) {
    values[i].a = a.load(std::memory_order_relaxed);
    values[i].b = b.load(std::memory_order_relaxed);
    values[i].c = c.load(std::memory_order_relaxed);
    var_to_inc->store(i + 1, std::memory_order_relaxed);  // 4
    std::this_thread::yield();
  }
}

void read_vals_relaxed(read_values* values) {
  while (!go) std::this_thread::yield();  // 5 自旋，等待信号
  for (unsigned i = 0; i < loop_count; ++i) {
    values[i].a = a.load(std::memory_order_relaxed);
    values[i].b = b.load(std::memory_order_relaxed);
    values[i].c = c.load(std::memory_order_relaxed);
    std::this_thread::yield();
  }
}

void print(read_values* v) {
  for (unsigned i = 0; i < loop_count; ++i) {
    if (i) std::cout << ",";
    std::cout << "(" << v[i].a << "," << v[i].b << "," << v[i].c << ")";
  }
  std::cout << std::endl;
}

void increment_and_print_relaxed() {
  a = b = c = 0;
  go = false;
  std::thread t1(increment_relaxed, &a, values1);
  std::thread t2(increment_relaxed, &b, values2);
  std::thread t3(increment_relaxed, &c, values3);
  std::thread t4(read_vals_relaxed, values4);
  std::thread t5(read_vals_relaxed, values5);

  go = true;  // 6 开始执行主循环的信号

  t5.join();
  t4.join();
  t3.join();
  t2.join();
  t1.join();

  print(values1);  // 7 打印最终结果
  print(values2);
  print(values3);
  print(values4);
  print(values5);
}

struct X {
  int i_;
  std::string s_;
};

std::atomic<X*> p;

void create_x() {
  X* x = new X;
  x->i_ = 42;
  x->s_ = "hello";
  a.store(99, std::memory_order_relaxed);
  p.store(x, std::memory_order_release);
}

void use_x(int& tmp_a) {
  X* x;
  while (!(x = p.load(std::memory_order_consume)))
    ;
  tmp_a = a.load(std::memory_order_relaxed);
  if (x->i_ != 42 || x->s_ != "hello") {
    std::cout << x->i_ << ", " << x->s_ << std::endl;
  }
  if (tmp_a != 99) {
    std::cout << tmp_a << std::endl;
  }
}

void memory_order_acquire_consume() {
  int tmp_a;
  int cnt = 0;
  do {
    tmp_a = 0;
    std::thread t1(create_x);
    std::thread t2(use_x, std::ref(tmp_a));
    t1.join();
    t2.join();
    ++cnt;
  } while (tmp_a == 99);
  std::cout << tmp_a << std::endl;
  std::cout << cnt << std::endl;
}

void HighConcurrency() {
  // 对比下使用条件变量的版本，虽然这么写不好，我就问你并发高不高嘛
  x = y = 0;
  std::thread t1([]() {
    while (x.load() != 1)
      ;
    std::cout << "t1 over" << std::endl;
  });
  std::thread t2([]() {
    while (x.load() != 1)
      ;
    std::cout << "t2 over" << std::endl;
  });
  std::thread t3([]() {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    x.store(1);
  });
  t1.join();
  t2.join();
  t3.join();
}

#endif