### 抽象类
1. 不能被实例化，只能被继承
2. 继承是为了代码`复用问题`
3. 可以使用多态
4. 基类可以被实例化，增加了类被误用的方法
5. 子类容易忘记重写log方法 ，导致编译错误

### 接口:定义和实现分离：
1. 侧重于`解耦`，提高代码的`扩展性`
2. C++ 实现方法：
  + 类中没有属性
  + 所有的方法都是抽象方法(virtual void func =0)
