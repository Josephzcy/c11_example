### 享元模式==》结构型设计模式
1. 应用场景
  + 特点：复用对象、节省内存
  + 共享的单元,不可改变的对象
2. 实现原理==》象棋
    + 运用map/list来缓存享元对象,通过get方法获取享元对象
    + 成员变量==》构造注入
    + 难点：哪些东西抽象成享元