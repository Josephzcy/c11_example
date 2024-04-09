

// todo::命令的请求封装成可调用对象
// todo::支持普通函数、lamada表达式
// todo::接受可调用对象，常量成员函数、接受非常量成员函数

// 成员函数指针int (C::*FunPtr)(int,int)
// tempalte<class R,class C,class... DAgrs,class P,class ...Args>
// void Wrap(R(c::*f))(DAgrs...),P&&p,Args&&...args{
//   return (*p.*f)(std::forward<Args>(args)...);
// }

#include <functional>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
template <typename R = void>  // 默认模板参数
class CommonCommand {
  using FuncType = std::function<R()>;  // 参数通过lamada捕获参数

 public:
  // todo::模板函数，非成员函数的情况 ,第三个模板参数，如果F不是成员函数指针类型，则为 void，否则不匹配
  template <typename F, typename... Args,
            typename = typename std::enable_if<!std::is_member_function_pointer<F>::value>::type>
  void Wrap(F&& f, Args&&... args) {
    func_vec_.push_back([&]() { return f(std::forward<Args>(args)...); });
  }

  // todo::非常量成员函数模板 , 类成员函数指针R(C::*f)(args...),类成员函数的地址传过来、类对象指针引用， 函数参数
  template <typename C, typename... DAgrs, typename P, typename... Args>
  void Wrap(R (C::*f)(DAgrs...), P&& obj, Args&&... args) {
    func_vec_.push_back([&, f]() { return (*obj.*f)(std::forward<Args>(args)...); });
  }

  template <typename C, typename... DAgrs, typename P, typename... Args>
  void Wrap(R (C::*f)(DAgrs...) const, P&& obj, Args&&... args) {
    func_vec_.push_back([&, f]() { return (*obj.*f)(std::forward<Args>(args)...); });
  }
  // todo:: 常量成员函数模板

  // template <typename C, typename... DArgs, typename P, typename... Args>
  // void Wrap2(R (C::*f)(DArgs...), P&& obj, Args&&... args) {
  //   return (obj.*f)(std::forward<Args>(args)...);
  // }

  void Excecute() {
    for (const auto& func : func_vec_) func();
  };

 private:
  std::vector<FuncType> func_vec_;
};

class Myclass {
  // todo:: 函数对象
  // operator() { std::cout << "Myclass func object..." << std::endl; }
  //成员函数
 public:
  int add(const int& a, const int& b) {
    std::cout << "men add func ..." << std::endl;

    return a + b;
  }
  // todo::类型转换运算符，不接收任何参数，将对象转化为目标类型。 形式： operator TargetType();
  operator int() { return value_; }
  operator std::string() { return str_value_; }

  int triple1() {
    std::cout << "nonconst func ..." << std::endl;
    std::cout << "value:" << value_ << std::endl;
    return value_;
  }

  int triple() const {
    std::cout << "const func ..." << std::endl;
    return value_ + 1;
  }

  // 运算符重载，有函数入参，返回值，形式如下： ReType operator<运算符>(parameter)
  std::string operator+(const Myclass& myclass) { return str_value_ + myclass.str_value_; }

  // todo::仿函数，重载调用运算符 operator()
  int operator()(const int& a, const int& b) {
    std::cout << "functor example ===" << std::endl;
    return a + b;
  }

 private:
  int value_{10};
  std::string str_value_{"Test Cast Convert"};
};

int add_one(int n) {
  std::cout << "normol function" << std::endl;
  return n + 1;
}

class Test {
 public:
  Test() = default;
  ~Test() = default;

 public:
  void start() {
    CommonCommand<int> common_command;

    Myclass my_obj_;
    common_command.Wrap(add_one, 1);
    // common_command.Wrap(
    //     [](int n) {
    //       std::cout << "lamada function..." << std::endl;
    //       return n + 1;
    //     },
    //     1);

    common_command.Wrap(
        []() {
          std::cout << "lamada function..." << std::endl;
          return 1;
        });

    // todo::仿函数
    common_command.Wrap(my_obj_, 3, 4);

    // todo:: 非常量成员函数
    common_command.Wrap(&Myclass::add, &my_obj_, 1, 2);
    common_command.Wrap(&Myclass::triple1, &my_obj_);
    common_command.Wrap(&Myclass::triple, &my_obj_);

    common_command.Excecute();
  }
  void TypeComvert() {
    Myclass my_obj_;
    std::string str = my_obj_;
    int num = my_obj_;
    std::cout << "str:" << str << std::endl;
    std::cout << "num:" << num << std::endl;
  }
};