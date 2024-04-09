// todo::大对象的创建和自动回收到对象池，避免对象的重复创建
// 堆内存空间，智能指针
// 自动回收对象，指定删除器

// todo:知识点，智能指针的原地构造、删除是一个可调用对象，如何指向已经分配的堆对象，传一个类型指针过来
// 如何获取生成对象，函数指针，function + 可变参数
// 如何获取对象类型，typeid(object).name()
// 支持不同参数的构建，可变参数
#include <functional>
#include <iostream>
#include <map>
#include <memory>

const int kMaxObjectNum = 10;
template <typename T>
class ObjectPool {
 public:
  ObjectPool() = default;
  ~ObjectPool() = default;

 public:
  template <typename... Args>
  using Contructor = std::function<std::shared_ptr<T>(Args...)>;

  template <typename... Args>
  void Init(std::size_t num_object, Args&&... args) {
    if (num_object > kMaxObjectNum || num_object < 0) throw std::logic_error("object is out of range");

    std::string object_name = typeid(Contructor<Args...>).name();
    for (auto i = 0; i < num_object; i++) {
      // 批量注入到容器之中,原地构造，并指定删除器
      object_map_.emplace(object_name,
                          std::shared_ptr<T>(new T(std::forward<Args>(args)...), [object_name, this](T* object) {
                            // 回收到对象池中
                            object_map_.emplace(std::move(object_name), std::shared_ptr<T>(object));
                            std::cout << "release object..." << std::endl;
                          }));
    }
  };

  // todo::根据参数确定返回哪个对象
  template <typename... Args>
  std::shared_ptr<T> Get() {
    // 返回对象池的对象
    std::string object_name = typeid(Contructor<Args...>).name();
    auto range = object_map_.equal_range(object_name);
    for (auto it = range.first; it != range.second; ++it) {
      auto ptr = it->second;
      object_map_.erase(it);
      return ptr;
    }
    return nullptr;
  }

 private:
  std::size_t object_num_;
  std::multimap<std::string, std::shared_ptr<T>> object_map_;
};

class BigClass {
 public:
  BigClass() = default;
  ~BigClass() = default;

 public:
  BigClass(const int&) { std::cout << "one para..." << std::endl; }
  BigClass(const int&, const int&) { std::cout << "two para..." << std::endl; }
  BigClass(const int&, const int&, const int&) { std::cout << "three para..." << std::endl; }
  int add(const int& a, const int& b) { return a + b; }
  void print() { std::cout << "test object..." << std::endl; }
};

class Test {
 public:
  Test() = default;
  ~Test() = default;

 public:
  void start() {
    ObjectPool<BigClass> object_pool;
    object_pool.Init(2, 1, 2);
    // auto p1 = object_pool.Get();
    // {
    //   auto p1 = object_pool.Get<int>();
    auto p2 = object_pool.Get<int, int>();
    //   auto p3 = object_pool.Get<int, int, int>();
    // }

    std::cout << "====test object..." << std::endl;
  }
};