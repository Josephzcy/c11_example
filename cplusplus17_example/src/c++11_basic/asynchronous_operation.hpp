// 获取结果 async 、std::async
// std::future,不能拷贝，不能赋值，只能移动
// get()
// wait()
// std::promise 在线程启动时传递进去。；线程在干完某些事情后，改变promise的结果，用关联的future获取结果，从而实现通信

#include <future>
#include <iostream>
class Test1 {
 public:
  Test1() = default;
  ~Test1() = default;

 public:
  std::future<int> my_future_;
  std::shared_future<int> my_share_future_;

 public:
  static int print() {
    std::cout << "static function print === " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    return 13;
  }
  void test12() {
    std::promise<int> my_promise;
    std::future<int> my_future = my_promise.get_future();

    std::thread t1([&my_promise]() {
      std::this_thread::sleep_for(std::chrono::milliseconds(300));

      std::cout << "my task has done" << std::endl;
      my_promise.set_value(300);
    });
    auto a = my_future.get();

    std::cout << "my future:" << a << std::endl;

    t1.join();

  }

  void test11() {
    std::packaged_task<int(int)> task([](int t) { return t + 2; });
    auto ret = task.get_future();  // 关联结果
    task(10);
    std::cout << "ret:" << ret.get() << std::endl;
  }

  void start() {
    // my_future_ = 10;
    // my_future_ = 15;

    std::future<int> aysnc_future = std::async(std::launch::async, &Test1::print);  //立即运行 deferred

    auto ret = std::async(std::launch::async, []() { return 11; });
    std::cout << "ret:" << ret.get() << std::endl;

    // 判断他是否执行完成
    std::future_status async_status;

    while (async_status != std::future_status::ready) {
      async_status = aysnc_future.wait_for(std::chrono::milliseconds(100));
      // 100ms判定状态
      if (async_status == std::future_status::timeout) {
        std::cout << "timeout" << std::endl;
      } else if (async_status == std::future_status::deferred) {
        std::cout << "deferred" << std::endl;
      } else if (async_status == std::future_status::ready) {
        std::cout << "ready..." << std::endl;
      }
    }
  };
};
