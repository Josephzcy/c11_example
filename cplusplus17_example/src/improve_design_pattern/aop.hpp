// todo::面向切面编程，将横切关注点和核心业务逻辑分离
// 核心切入点、横切切入点
//动态切入，代理模式。 核心逻辑前后 插入非核心代码逻辑

// 传统模式，1. 耦合性太强，每个切面必须继承基类，并实现基类的方法
//不够灵活，不能自由组合各个切面

#include <iostream>
#include <memory>
class IAOP {
 public:
  virtual void DoSomething() = 0;
};

class TypicalAOP : public IAOP {
 public:
  virtual void DoSomething() override { std::cout << "typical aop ..." << std::endl; }
  virtual ~TypicalAOP() {}
};
class TypicalAOProxy : public IAOP {
 public:
  virtual void DoSomething() override {
    std::cout << "before typical aop proxy..." << std::endl;

    std::cout << "typical aop proxy..." << std::endl;
    std::cout << "after typical aop proxy..." << std::endl;
  }

  TypicalAOProxy(IAOP* aop) : aop_(aop) {}
  virtual ~TypicalAOProxy() {}

 private:
  IAOP* aop_{nullptr};
};

class Test {
 public:
  void start() {
    //模板特化+ 构造函数入参(原地构造)
    std::shared_ptr<IAOP> aop_proxy = std::make_shared<TypicalAOProxy>(new TypicalAOP);

    aop_proxy->DoSomething();
  }
};

// 如何改进? 切面作为模板参数，通过可变模板来代替切面的组合
// 在 拦截方法之前执行切面代码。Before(Args...),after(Args...)

// #define HAS_MEMBER(member)
// template <typename F, typename... Args>
// struct {
//  private:
//  public:
//  enum{
//     value = std::is_same<decltype(Check<T>(0)),std::true_type::value>
//  }
// };

// todo::织入普通函数、织入lamada 表达式