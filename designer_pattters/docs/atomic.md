# 原子变量与内存模型

内存模型没有明确的定义基本部件应该如何工作的话，之前介绍的那些工具就无法正常工作。那为什么大多数程序员都没有注意到它呢？当你使用互斥量保护你的数据和条件变量，或者是“期望”上的信号事件时，对于互斥量*为什么*能起到这样作用，大多数人不会去关心。只有当你试图去“接触硬件”，你才能详尽的了解到内存模型是如何起作用的。

## 原子变量

是一个模板类，可以通过is_lock_free()来判断是否在内部使用上没有使用锁。

对这些原子变量，有对应的存储顺序，分为3类
1. Store操作，可选如下顺序：memory_order_relaxed, memory_order_release, memory_order_seq_cst。<br>
2. Load操作，可选如下顺序：memory_order_relaxed, memory_order_consume, memory_order_acquire, memory_order_seq_cst。<br>
3. Read-modify-write(读-改-写)操作，可选如下顺序：memory_order_relaxed, memory_order_consume, memory_order_acquire, memory_order_release, memory_order_acq_rel, memory_order_seq_cst。<br>

## 内存序

### memory_order_seq_cst
默认内存序：

对于每一步，随机选择一个线程，然后执行该线程执行的下一步（即程序或编译顺序）。 重复这个过程，直到整个程序终止。 这实际上等效于按（程序或编译）顺序执行所有线程的所有步骤，并以某种方式交错它们，从而产生所有步骤的单一总顺序。

不允许重新排序线程的步骤。 因此，无论何时访问对象，都会检索按此顺序存储在对象中的最后一个值。 可以理解为这种交织的执行被称为顺序一致。

我们来看第一个例子：
```
std::atomic<int> x, y;
std::atomic<bool> go;

int main() {
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
```

三个线程随着go统一开始，t1将x存为1, t2将y存为2, t3读取x、y

那么t3可能看到哪几种可能性？
(0, 0), (0, 2), (1, 0), (1, 2)

如果我们把t1,t2合并呢？效果如何？
```
int main() {
    x = y = 0;
    go = false;
    std::thread t1([]() {
      while (!go)
        ;
      x.store(1);
      // std::this_thread::sleep_for(std::chrono::nanoseconds(1));
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
```

来，有请一个幸运儿回答

## memory_order_relaxed

关于std::memory_order_relaxed具备如下几个功能：
  1. 作用于原子变量
  2. 不具有synchronizes-with关系
  3. 对于同一个原子变量，在同一个线程中具有happens-before关系（言外之意，不同的原子变量不具有happens-before关系，可以乱序执行）
  4. 由上述可知，在一个线程中，如果某个表达式已经看到原子变量的某个值a，则该表达式的后续表达式只能看到a或者比a更新的值

仍然拿上面的例子，只是做了一点点修改, store与load的时候使用memory_order_relaxed

```
  int main() {
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
      xy_set.emplace(std::pair<int, int>(x, y));
    });
    go = true;
    t1.join();
    t2.join();
    t3.join();
  }
```
这时候，xy有几种可能性？

同样的，我们将t1 t2合并
```
  int main() {
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
      xy_set.emplace(std::pair<int, int>(x, y));
    });
    go = true;
    t1.join();
    t2.join();
  }
```

这时候x, y可能会有什么可能性？

这个run起来比较慢(现在cpu太快了)
![运行可能性](./picture/captrue.png)


我们来看一个稍微复杂点的例子
3个增加线程，2个打印线程

来看看这个打印，暗示了什么？

(0,1,10),(1,3,10),(2,4,10),(3,5,10),(4,6,10),(5,7,10),(6,8,10),(7,9,10),(8,10,10),(9,10,10)
(0,0,10),(1,1,10),(1,2,10),(2,3,10),(2,4,10),(4,5,10),(5,6,10),(6,7,10),(7,8,10),(8,9,10)
(0,0,0),(0,0,1),(0,0,2),(0,0,3),(0,0,4),(0,0,5),(0,0,6),(0,0,7),(0,0,8),(0,0,9)
(0,0,1),(0,0,2),(0,0,4),(0,0,5),(0,0,6),(0,0,7),(0,0,8),(0,0,9),(0,0,10),(0,0,10)
(0,0,10),(0,0,10),(0,0,10),(0,0,10),(0,0,10),(0,0,10),(0,0,10),(0,0,10),(0,0,10),(0,0,10)

第二行，递增的是第二个数字，(1,1,10),(1,2,10)，这里，第一个数保持一样，意味着什么？

意味着使用std::memory_order_relaxed，只保证不会回溯

### 一个例子

想想一个记数本，这个本子就是原子变量。

现在有n个房子，这n个房子代表n个线程，里头有一个接线员，你可以请他在本子上写数字就是store的过程，去询问这个本子最新的数字就是load的过程

以上都很好，问题是除非他们之前互相告诉，不然不同屋子里头的人是不知道数字被更新。

![运行可能性](./picture/5-5.png)

## std::memory_order_acquire/release

happens-before 规则：前一个操作的结果对后续操作时可见的。

这是c++的定义：
Let A and B represent operations performed by a multi-threaded process. If A happens-before B, then the memory effects of A effectively become visible to the thread performing B before B is performed.

acquire/release与顺序一致性内存序相比是更宽松的内存序模型，其不具有全局序，性能更高。

关于acquire/release的核心是：同一个原子变量的release操作同步于一个acquire操作.

关于acquire/release， 首先看一下共享的部分

atomic operations on the same object may never be reordered
针对同一个对象的原子操作不会被重排序。
关于acquire语义的定义

(non-)atomic load/store operations that are sequenced after an acquire operation A may not be reordered before A.
acquire 操作A之后的原子或者非原子load/store操作不能被重排到操作A之前
关于release语义的标准定义

(non-)atomic write/load operations that are sequenced before a release operation A may not be reordered after A,
release操作A之前的原子或者非原子store/load操作不能被重排到操作A之后

请看例子memory_order_acquire_release

## memory_order_consume

std::memory_order_consume仅仅只用来补充该系列的完整性，在实际代码中不能使用该内存序，且在GCC中会自动将该内存序转换为std::memory_order_acquire。
[参考](https://preshing.com/20141124/fixing-gccs-implementation-of-memory_order_consume/)
简单的来说，consume操作只对其有数据/地址等依赖的load操作有happen-before关系。
a同x没有任何数据/地址相关依赖，所以不存在相应的happen-before关系。
不过在x86下consume和acquire一个样子