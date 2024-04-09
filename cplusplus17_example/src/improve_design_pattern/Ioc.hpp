
//通过控制反转:
// todo:组件不再直接创建或管理其依赖对象，而是通过外部提供的接口或容器来获取依赖对象。这种机制可以让对象之间的关系在外面组装
// todo::这样，控制权从上层组件转移到了外部环境，实现了控制关系的反转。

// todo::好处，对象创建上获取极大的灵活性，大大降低了创建对象时的灵活性
// 对象工厂的能力； 创建依赖对象
#include <iostream>
#include <memory>
// 创建对像及其依赖的对象
// 实现原理
// 知识点：模板函数特化

// 要解决的问题：对象的创建解耦
// 让应用(要创建的对像)不再直接依赖于对象的创建，而是依赖于某种机制
// 这种机制可以在外面组装对象的依赖关系，并且可以根据需求进行灵活的配置，从而获取想要的目标对象
// apply:
// 1.插件系统
// 2. 架构设计和分层
// 实现方法：构造依赖注入、委托实现

class IIOC {
 public:
  virtual double Carculate(double a, double b) const = 0;
};

class TypicalIoc : public IIOC {
 public:
  virtual double Carculate(double a, double b) const override {
    std::cout << "=== typical ioc:" << std::endl;
    return a + b;
  }
};

class TrueCarculate {
 private:
  std::shared_ptr<IIOC> ioc_{nullptr};

 public:
  TrueCarculate(std::shared_ptr<IIOC> ioc) : ioc_(ioc) {}
  void Test(const double& a, const double& c) {
    std::cout << "test ioc :" << ioc_->Carculate(a, c) << std::endl;

    // ioc_->Carculate(a, c);
  }
};
class Test {
 public:
  void Test1() {
    std::shared_ptr<IIOC> a = std::make_shared<TypicalIoc>();
    std::shared_ptr<TrueCarculate> b = std::make_shared<TrueCarculate>(a);
    b->Test(3, 4);
  }
};

// ioc容器
// 1.不仅创建任何对象，而且可以根据配置动态创建对象，工厂模式，
// 类型擦除，std::function<T*()> ，没有参数的可调用对象，lamada[]{new T()}
// any
// 支持任意参数：可变模板
// 2. 创建可配置的依赖对象：可以创建依赖对象并且依赖对象是可以配置
// 3. 依赖关系：
//参数化配置依赖关系，IOC创建依赖关系--继承关系，函数模板
// IOC 容器配置依赖关系(模板特化)

// 实验原理:
// 构造函数依赖注入

// todo:: 模板函数实例化
//模板参数推断：从左往又，根据参数类型，编译器在编译期器实例化函数
//如果指定了部分模板参数，编译器会尝试根据函数参数的类型来推断剩余的模板参数

template <typename T, typename U>
void MyFunction(T t, U u) {
  // 函数实现
}

//................................................
#include <any>
#include <functional>
#include <map>
#include <memory>
#include <type_traits>
#include <unordered_map>
class IocContainer {
  // 创建接口
  // 获取接口
  // 容器
 public:
  //通过模板参数的对模板函数返回值限制从而实现重载，用过lamada的捕捉可以可变参数或者把可变参数作为模板
  template <typename A, typename Derived, typename... Args>
  typename std::enable_if<!std::is_base_of<A, Derived>::value>::type RegisterType(const std::string& class_name) {
    std::function<std::shared_ptr<A>(Args...)> func_object = [](Args&&... args) {
      std::shared_ptr<Derived> derived_object = std::make_shared<Derived>(args...);

      std::shared_ptr<A> base_object = std::make_shared<A>(derived_object);
      return base_object;
    };
    RegisterType(class_name, func_object);
  }

  // todo::通过std::enable_if对模板函数返回值限制做到模板重载
  template <typename A, typename Derived, typename... Args>
  typename std::enable_if<std::is_base_of<A, Derived>::value>::type RegisterType(const std::string& class_name) {
    std::function<std::shared_ptr<A>(Args...)> func_object = [](Args&&... args) {
      std::shared_ptr<A> base_object = std::make_shared<Derived>(args...);
      return base_object;
    };
    RegisterType(class_name, func_object);
  }
  // Todo::fault,依赖之间有相同的构造参数

  //普通类型的对象
  template <typename T, typename... Args>
  void RegisterSimpleType(const std::string& class_name) {
    std::function<std::shared_ptr<T>(Args...)> func_object = [](Args&&... args) {
      return std::make_shared<T>(args...);
    };
    RegisterType(class_name, func_object);
  }

  template <typename T, typename... Args>
  std::shared_ptr<T> Resolved(const std::string& name, Args... args) {
    auto it = object_map_.find(name);
    if (it != object_map_.end()) {
      // todo::any ==>function ==>智能指针
      std::function<std::shared_ptr<T>(Args...)> func_object =
          std::any_cast<std::function<std::shared_ptr<T>(Args...)>>(object_map_[name]);
      return func_object(args...);
    }
    return nullptr;
  }

 private:
  void RegisterType(const std::string& class_name, const std::any& constructor) {
    if (object_map_.find(class_name) != object_map_.end()) throw std::invalid_argument("this key has already exist");
    object_map_.emplace(class_name, constructor);
  }

  //通过any解决不同的func,从而支持所有的类型
  std::unordered_map<std::string, std::any> object_map_;
};

// todo:: 测试驱动开发
class Base {
 public:
  void Print(const std::string& str) { std::cout << "Base str::" << str << std::endl; }
};
class Derived : public Base {
 public:
  void Print(const std::string& str) { std::cout << "Derived str::" << str << std::endl; }
};

class DependBase {
 public:
  DependBase(std::shared_ptr<Base> base_ptr) : base_ptr_(base_ptr) {}
  void Print() { std::cout << "DependBase Base ......." << std::endl; }

 private:
  std::shared_ptr<Base> base_ptr_;
};
class IAanimal {
 public:
  void Print(const std::string& str) { std::cout << "IAanimal str::" << str << std::endl; }
};
class Dog : public IAanimal {
 public:
  void Print(const std::string& str) { std::cout << "Dog str::" << str << std::endl; }
};

class Bus {
 public:
  void Print(const std::string& str) { std::cout << "Bus str::" << str << std::endl; }
};

class Car {
 public:
  void Print(const std::string& str) { std::cout << "Car str::" << str << std::endl; }
};

class IocTest {
 public:
  void start() {
    //测试驱动开发
    std::string str = "hello";
    IocContainer ioc;
    ioc.RegisterType<Base, Derived>("Derived");
    auto a = ioc.Resolved<Base>("Derived");      // 基类指针不能转为子类指针 
    a->Print(str);

    ioc.RegisterType<IAanimal, Dog>("Dog");
    auto b = ioc.Resolved<IAanimal>("Dog");
    b->Print(str);

    // 构造依赖注入
    ioc.RegisterType<DependBase, Derived>("DependBase");
    auto d = ioc.Resolved<DependBase>("DependBase");
    d->Print();

    // // 普通对象
    ioc.RegisterSimpleType<Bus>("Bus");
    auto c = ioc.Resolved<Bus>("Bus");
    c->Print(str);
  }
};

// 总结:
// 1. 支持任意的std::function
// 2. 支持带参数的构造函数
// 3. 自动管理对象，不需要手动释放内存
// 4. 通过参数化配置，注册依赖关系
// 5. 支持基层关系、接口关系、 和依赖关系 对象的创建

//当使用尖括号指定模板参数的类型时，可以明确指定使用的具体类型，以消除二义性并进行必要的类型转换
// 通过使用尖括号指定模板参数的类型，我们可以明确告诉编译器我们想要使用的具体类型。
//这种显式指定可以提高代码的可读性和可维护性，使代码更加清晰明了
#include <cmath>
#include <iostream>
// 自定义类型
struct Point {
  int x;
  int y;

  Point(int a, int b) : x(a), y(b) {}
};

// 模板函数，计算两个点之间的距离
template <typename T, typename U>
double distance(const T& p1, const U& p2) {
  int dx = p2.x - p1.x;
  int dy = p2.y - p1.y;
  return std::sqrt(dx * dx + dy * dy);
}
