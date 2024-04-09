/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-07-31 11:17:54
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-02 10:29:02
 * @fileclassName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/subsrc/c++_example/ClassInfoManager.hpp
 * @Description:
 */
/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-07-31 11:17:54
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-02 10:27:58
 * @fileclassName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/subsrc/c++_example/ClassInfoManager.hpp
 * @Description:
 */
//! c++ 实现反射机制:工厂模式+ 回调机制
//! 工厂功能：
//! 1. 注册产品：动态注册  ？模板或者#define
//! 2. 生产产品:产品的生产产品功能
//! 3. 具体共产
//! 产品的功能:
//! 产品生产接口CreateObject()
//! 如何注册到工厂中: way1: 共产对外的注册接口

//! 减少注册环节，静态成员产品变量，构造注入
#ifndef Reflection_HPP__
#define Reflection_HPP__
#include <iostream>
#include <map>

namespace dynamic_factory {
class IAbstractFactory;
class ClassInfoManager;
typedef IAbstractFactory* (*ObjectCreateFun)();

typedef std::map<std::string, ClassInfoManager*> ClassInfoMap;
ClassInfoMap* gPtr_class_info_map = nullptr;  //? 指针初始化问题

class ClassInfoManager {
 public:
  ClassInfoManager(const std::string& class_name, ObjectCreateFun create_func)
      : class_name_(class_name), create_func_(create_func) {
    if (gPtr_class_info_map == nullptr) {
      gPtr_class_info_map = new ClassInfoMap;
    }
    if (gPtr_class_info_map->find(this->GetClassName()) == gPtr_class_info_map->end()) {
      gPtr_class_info_map->insert(std::map<std::string, ClassInfoManager*>::value_type(this->GetClassName(),
                                                                                       this));  //?std::make_pair不行
    }
  }
  virtual ~ClassInfoManager() { std::cout << "ClassInfoManager deconstructor........." << std::endl; }

  IAbstractFactory* CreateObject() { return create_func_ ? create_func_() : nullptr; }
  //?对外访问接口
  const std::string GetClassName() const { return class_name_; }
  ObjectCreateFun GetConstructorFunc() { return create_func_; }
  bool IsDynamic() const { return create_func_ != nullptr; }

 private:
  std::string class_name_;
  ObjectCreateFun create_func_;
};

class IAbstractFactory {
 public:
  virtual ClassInfoManager* GetClassInfo() const = 0;

  static IAbstractFactory* GetClassByName(const std::string& class_name) {
    if (gPtr_class_info_map->find(class_name) != gPtr_class_info_map->end()) {
      return gPtr_class_info_map->at(class_name)->CreateObject();
    }
    std::cout << "concrate product " << class_name << " not found" << std::endl;
  }

 public:
  virtual ~IAbstractFactory() = default;
  IAbstractFactory() = default;
};

class ConcreteFactory : public IAbstractFactory {
 public:
  ConcreteFactory() { std::cout << "concrete factory constructor........." << std::endl; };
  ~ConcreteFactory() { std::cout << "concrete factory deconstructor........." << std::endl; };
  virtual ClassInfoManager* GetClassInfo() const { return &class_info_; }
  static IAbstractFactory* CreateObject() { return new ConcreteFactory; }

 private:
  static ClassInfoManager class_info_;
};
ClassInfoManager ConcreteFactory::class_info_("B", ConcreteFactory::CreateObject);

#define DECLEAR_CLASS(classname)           \
 public:                                   \
  static IAbstractFactory* CreateObject(); \
                                           \
 protected:                                \
  static ClassInfoManager class_info_;     \
  virtual ClassInfoManager* GetClassInfo() const { return &class_info_; }

#define IMPLEMENT_CLASS_COMMON(className, func) \
  ClassInfoManager className::class_info_((#className), (ObjectCreateFun)func);

#define IMPLEMENT_CLASS(className)                           \
  IMPLEMENT_CLASS_COMMON(className, className::CreateObject) \
  IAbstractFactory* className::CreateObject() { return new className; }



class C : public IAbstractFactory {
  DECLEAR_CLASS(C);

 public:
  C(/* args */) { std::cout << "C construct....." << std::endl; }
  ~C() { std::cout << "C deconstruct....." << std::endl; }
};
IMPLEMENT_CLASS(C);

class D : public IAbstractFactory {
  DECLEAR_CLASS(D);

 public:
  D(/* args */) { std::cout << "D construct....." << std::endl; }
  ~D() { std::cout << "D deconstruct....." << std::endl; }
};
IMPLEMENT_CLASS(D);

class E : public IAbstractFactory {
  DECLEAR_CLASS(E);

 public:
  E(/* args */) { std::cout << "E construct....." << std::endl; }
  ~E() { std::cout << "E deconstruct....." << std::endl; }
};
IMPLEMENT_CLASS(E);

}  // namespace dynamic_factory

#endif
