/***
 * @Copyright: Copyright 2023 MINIEYE
 * @Author: zhangchengyu zhangchengyu@minieye.cc
 * @Date: 2023-08-01 16:52:13
 * @LastEditors: zhangchengyu zhangchengyu@minieye.cc
 * @LastEditTime: 2023-08-01 16:52:14
 * @fileName: Do not edit
 * @FilePath: /mviz_apa/submodule/designer_pattters/subsrc/c++_example/abstract_factory.hpp
 * @Description:
 */

#ifndef ABSTRACT_FACTORY_HPP__
#define ABSTRACT_FACTORY_HPP__

#include <iostream>
class IAbstractFactory {
  virtual ~IAbstractFactory() {}
  virtual void register() = 0;
  virtual IAbstractFactory* CreateObject() = 0;
};
template <class ProductType>
class AbstractFactory {
 public:
  static AbstractFactory<ProductType>& Instance() {
    static AbstractFactory<ProductType> instance;
    return instance;
  }

  void RegisterProduct(const string& product_name, ProductType* product) { product_map_[product_name] = product; }

  ProductType* GetProduct(const string& product_name) {
    if (product_map_.find(product_name) != product_map_.end()) {
      return product_map_.at(product_name)->CreateProduct();
    }
    std::cout << "product " << product_name << " not found" << std::endl;
    return nullptr;
  }

 private:
  std::map<std::string, ProductType*> product_map_;

 private:
  AbstractFactory();
  ~AbstractFactory();
  AbstractFactory(const AbstractFactory&);
  AbstractFactory& operator=(const AbstractFactory&);
};

template <class ProductType>
class IProductRegister {
 public:
  ProductType* CreateProduct() = 0;

 protected:                       //?子类函数可以直接访问
  virtual ~IProductRegister() {}  //? 防止内存泄露
  void RegisterProduct() {}

 private:
  IProductRegister(const IProductRegister&);
  IProductRegister& operator=(const IProductRegister&);
}

template <class ProductType, class ProductImpl>
class ProductRegister : public IProductRegister<ProductType> {
 public:
  ProductType* CreateProduct() { return new ProductImpl(); }
  void RegisterProduct(const string& name) {  //! 构造注入
    AbstractFactory<ProductType>::Instance().RegisterProduct(name, this);  //?传递this指针或者函数指针

  }
}
#endif