#include <functional>
#include <iostream>
#include <optional>
#include <type_traits>

//实现懒性加载：
// 1. 擦擦入参类型，lamada[]{} 或者 std::bind(f,std::forward<Args>(args)...)
// 2. 支持任意类型的可调动对象std::function<T()>
// 3. 接收空值的std::optional<T>

template <typename T>
class Lazy {
 public:
  Lazy(){};

  template <typename F, typename... Args>  // 函数模板
  Lazy(F& fun, Args&&... args) {
    func_ = [&fun, &args...]() { return fun(args...); };
  }

  T& Load() {
    if (!value_.has_value()) {
      value_ = func_();
    }
    return *value_;
  }
  bool IsInitValue() const { return value_.IsInit(); }

 private:
  std::function<T()> func_;
  std::optional<T> value_;
};

template <typename Func, typename... Args>
Lazy<typename std::result_of<Func(Args...)>::type> RegisterLazy(Func&& fun, Args&&... args) {
  return Lazy<typename std::result_of<Func(Args...)>::type>(std::forward<Func>(fun), std::forward<Args>(args)...);
}

int func(int x) { return x * 2; }