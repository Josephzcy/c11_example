#include <functional>
#include <iostream>
#include <list>
#include <vector>

class SubjectInterface;
class ObserverInterface {
 public:
  virtual ~ObserverInterface() = default;  // 防止内存泄漏
  virtual void update(SubjectInterface* subject) = 0;

 protected:
  ObserverInterface() = default;
};

class ConcreteObserverA : public ObserverInterface {
 public:
  ConcreteObserverA() = default;
  ~ConcreteObserverA() = default;
  virtual void update(SubjectInterface* subject) override { std::cout << "ConcreteObserverA::update" << std::endl; }
};

class ConcreteObserverB : public ObserverInterface {
 public:
  ConcreteObserverB() = default;
  ~ConcreteObserverB() = default;
  virtual void update(SubjectInterface* subject) override { std::cout << "ConcreteObserverB::update" << std::endl; }
};
class SubjectInterface {
 public:
  ~SubjectInterface() = default;
  SubjectInterface() = default;
  void attach(ObserverInterface* observer) { observers_.emplace_back(observer); }
  void detach(ObserverInterface* observer) { observers_.pop_front(); }

  void notify() {
    for (const auto& observer : observers_) {
      observer->update(this);
    };
  }

 public:
  std::list<ObserverInterface*> observers_;
};

// 1. todo::继承是强对象关系，不够灵活,委托类型来限定观察者
//! 被通知接口参数化和std::function 来代替继承
// 2. todo::观察者被通知的接口参数不支持变化，不够灵活
//! 通过委托类型来限定观察者
//! 实现思路，
// event 类模板func + function，用来注册事件

template <typename Func>
class Event {
 public:
  Event() = default;
  ~Event() = default;

  void Register(const Func& func) { func_.emplace_back(func); }
  void Delete(){
    std::cout<<"delete"<<std::endl;
  }

  template <typename... Args>
  void Notify(Args&&... args) {
    for (const auto& func : func_) {
      func(std::forward<Args>(args)...);
    };
  }

 private:
  std::vector<Func> func_;
};


void print(int,int) { std::cout << "hello world" << std::endl; }
struct stA {
  int a, b;
  void printA(int a, int b) { std::cout << "stA hello world" << std::endl; }
};

