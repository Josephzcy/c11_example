#include <functional>
#include <iostream>
#include <memory>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
//需要解决的问题?
// 1. 同类型的拷贝构造、移动构造和赋值构造
// 2. 如果接收普通类型？
// 1. std::decay 去掉引用和顶层cv
// 2. 用基类指针指向派生类的对象，具体值指通过通过子类构造函数去接管, std::type_index 保存变量类型的名字
// 3. 非any类型如何处理，== 》 std::enable_if<condition::value,type>::type
// 3. 如何实现转化其他类型的接口？
// dynamic_cast 下行转化
// dynamic_cast<Derived*>(basePtr);
// type_info 和type_index ?
// 1. type_index 包装了type_info,提供了比较运算符
// 8.std::unique_ptr 不支持拷贝和移动构造；独占指针
class Any {
 public:
  Any(void) : obj_type_info_(typeid(void)) {}
  Any(const Any& any) : ptr_(any.Clone()), obj_type_info_(any.obj_type_info_) {}     // 拷贝构造
  Any(Any&& any) : ptr_(std::move(any.ptr_)), obj_type_info_(any.obj_type_info_) {}  //移动构造

  // todo::赋值构造
  Any& operator=(const Any& a) {
    if (ptr_ == a.ptr_) {
      return *this;
    }
    ptr_ = a.Clone();
    obj_type_info_ = a.obj_type_info_;
    return *this;
  }

  // todo:: 接收非any类型，模板构造函数,判断入参是否是any ,如果不是any ,则为U，如果是any
  template <typename U,
            typename T = typename std::enable_if<!std::is_same<typename std::decay<U>::type, Any>::value, U>::type>
  Any(U&& value)  // todo::去掉类型后，实例化派生类
      : ptr_(new Derived<typename std::decay<U>::type>(std::forward<U>(value))),
        obj_type_info_(typeid(typename std::decay<U>::type)) {}

  // todo::一些辅助函数 is ,is_null
 public:
  // any<U>.is(); 判断接管之后的类型
  template <typename U>
  bool is() const {
    return obj_type_info_ == std::type_index(typeid(U));
  }

  // 智能指针转化为bool 值
  bool is_null() { return !bool(ptr_); }

  // todo::转化函数怎么写？any转化为目标类型，any<U>();
  template <typename U>
  U& AnyCast() {
    if (!is<U>()) {
      std::cout << "can not cast " << typeid(U).name() << "to " << obj_type_info_.name() << std::endl;
      throw std::bad_cast();
    }
    auto derived_ptr = dynamic_cast<Derived<U>*>(ptr_.get());
    return derived_ptr->value_;
  }

 public:
  struct Base;                            // 前向申明
  using BasePtr = std::unique_ptr<Base>;  // todo::解决这个问题，需用到前向申明

 public:
  BasePtr ptr_{nullptr};
  std::type_index obj_type_info_;

 public:
  // 对外接口
  BasePtr Clone() const {
    if (ptr_ != nullptr) {
      return ptr_->clone();
    }
    return nullptr;
  }

 public:  // 必须在初始化列表中初始化的情况
  struct Base {
    Base() = default;
    ~Base() = default;
    virtual BasePtr clone() const = 0;
  };

  // 子类需要实现:1. 管理传递进来的变量,任何类型
  template <typename T>
  struct Derived : Base {
    template <typename U>
    Derived(U&& value) : value_(std::forward<U>(value)) {}
    // virtual BasePtr clone() override { return std::make_unique<Derived<T>>(value); }

    Derived() = default;
    virtual ~Derived() = default;

    virtual BasePtr clone() const override { return std::make_unique<Derived<T>>(value_); }

   public:
    T value_;
  };
};