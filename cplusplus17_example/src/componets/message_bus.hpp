#include <iostream>
// todo :目的：解决对象关系复杂，耦合性较强的问题
// 功能：
// 1. 通用消息的定义
// 2. 消息的注册
// 3. 消息的分发

// 消息总线的应用实例：
// 1.收到消息后怎么告诉消息发送者？
// 注册主题类的某个对象，接收者收到消息后，给subject发消息:
// 按topic调用某个消息总线的可对象对象

// 1. 观察者定义 、主题的定义
// 2. 构造定义注入
#include <any>
#include <functional>
#include <unordered_map>

#include "NonCopyable.hpp"
class MessageBus : public NonCopyable {
 public:
  MessageBus() = default;
  ~MessageBus() = default;

 public:
  template <typename F>
  void Attach(F&& f, const std::string topic) {
    Add(topic, std::move(f));
  };
  void Remove(const std::string& topic){};

  template <typename R, typename... Args>
  void SendReq(Args&&... args, const std::string&){};

 private:
  template <typename F>
  void Add(const std::string& topic, F&& f) {
    std::string msg_type = topic + typeid(F).name();
    msg_map_.emplace(msg_type, std::forward<F>(f));
  }
  std::unordered_map<std::string, std::any> msg_map_;
};

MessageBus g_message_bus;
const std::string kOTopic = "observer";
const std::string kSTopic = "subject_topic";
// todo::观察者和主题在构造时注入到消息总线上去
class Observer1 {
 public:
  void Driver(int speed) { std::cout << "Observer1 drive..." << std::endl; }
  Observer1() {
    g_message_bus.Attach([this](int speed) { Driver(speed); }, kOTopic);
  }
};
class Observer2 {
 public:
  void Driver(int speed) { std::cout << "Observer2 drive..." << std::endl; }
  Observer2() {
    g_message_bus.Attach([this](int speed) { Driver(speed); }, kOTopic);
  }
};
class Subject {
 public:
  void SubjectDriver() { std::cout << "SubjectDriver drive..." << std::endl; }
  Subject() {
    g_message_bus.Attach([this]() { SubjectDriver(); }, kSTopic);
  }
  void SendReq(const std::string&) { g_message_bus.SendReq<void, int>(50, kSTopic); }
};

class Test {
 public:
  Test() = default;
  ~Test() = default;

 public:
  void start() {
    Observer1 observer1;
    Observer2 observer2;
    Subject concept_subject;
    concept_subject.SendReq(kSTopic);
  }

 private:
  std::string topic{"observer"};
  std::string subject_topic{"subject"};
  MessageBus message_bus;
};