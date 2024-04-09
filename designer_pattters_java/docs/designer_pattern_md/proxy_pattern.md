### 代理模式
  + 引入代理类给原始类添加附件功能
1. 代理模式的原理和实现
  + 类定义
    + 代理类、被代理类
  + 组合实现：被代理类作为代理类的成员变量，通过构造注入+ 委托实现
  + 继承实现：代理类继承自被代理类，重写相关接口
2. 动态代理模式的原理和实现
  + 为每个被代理类动态的创建代理类，java反射语法
3. 代码模式的应用场景
  + 解耦：非业务功能和业务功能解耦
  + RPC
  + 缓存