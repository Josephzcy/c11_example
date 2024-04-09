#include <functional>
#include <iostream>
#include <list>
// todo:: 实现的功能
// 1. 核心功能：add、take
// 2. 辅助功能：队列为空、队列为满，队列的实时长度
// 3. 防止内存爆炸，最大任务量限制
// 4. 栈空间占满，使用堆内存空间 --new make_shared<std::thread> std::thread
//* 5. 如何进行数据同步？cv + lock 机制
// 6. 业务流程功能：start、stop、suspend、resume
// 7. 扩展性：模板类来实现，支持不同的类型


constexpr int KmaxTaskNum = 20;
class SysQuene {
 public:
  using Task = std::function<void()>;  // lamada 捕捉外部参数

 public:
  bool NotEmpty() {
    bool empty = quene_list_.empty();

    return !empty;
  }
  bool NotFull() {
    if (quene_list_.size() != KmaxTaskNum)
      return true;
    else
      return false;
  }
  bool Stop() { return true; }

  std::size_t GetQueneLength() { return quene_list_.size(); }

  // 核心功能：添加任务
 public:
  void AddTask(Task task) { quene_list_.push_back(task); }
  Task TakeTask() {
    Task task = quene_list_.front();
    quene_list_.pop_front();
    return task;
  }

 private:
  std::list<Task> quene_list_;
  bool is_empty_{true};
  bool is_full_{false};

};

// todo:: 测试驱动开发
struct Test {
  /* data */
};
