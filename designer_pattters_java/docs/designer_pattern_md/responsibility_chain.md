### 职责链模式
+ 设计原理
  + 定义：将接收对象串成一条链，沿着这条链处理请求，直到链上某个对象能够处理它为止
+ 作用：
  + 复用
  + 扩展：在不改变框架源代码的基础上，基于扩展点定制化框架功能
+ 实现原理
  + 类定义：
    + 处理器接口 + 具体处理器
    + 处理链：集成并提供使用入口
    + 框架代码
    + 客户端代码：使用代码
+ UGC:敏感词过滤
### *代码存在的问题

### 设计模式是为了应对代码复杂性
+ 
+ 大块代码逻辑拆分成函数
+ 大类拆分成小类
### 提高代码扩展性
### 应用场景
  + 对扩展开放，对修改关闭：在框架开发中：为框架提供`扩展点`：在不改动原框架源码的基础上，基于扩展点添加新的功能
    + 继承接口类，并重写抽象方法  
  + 过滤器
  + 拦截器
  + 插件 
