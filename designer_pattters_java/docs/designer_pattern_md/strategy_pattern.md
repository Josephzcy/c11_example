### 策略模式原理
+ 定义：一个接口，包含若干种算法定义
+ 创建：工厂模式(查表)
+ 使用:service(客户端代码)
+ 入口：main
+ 作用：
  + 解耦策略的定义、创建和使用，2. 控制代码的复杂度
### 设计原则和设计思想
1. 设计原则
2. 设计思想：
  2. 代码规范
  3. 代码质量评估规范
    + 可读性
    + 可复用性
    + 扩展性
    + 可维护性
### 核心
1. 运行时动态确定在代码中使用哪种策略
  + 配置、用户输入、计算结果选择某种策略
### 设计意图和应用场景
  + 查表法：解决if/else或者switch/case过长的问题
  + 查表法+条件遍历+类/方法包装
### 应用举例
1. 数据量无法一次性加入内存中怎么解决排序问题？
  + 外排序
  + `单机版`MapReduce:多核并发
  + MapReduce:多核并发

### 对象交互方式
+ 依赖注入
+ 设值注入
+ 就地构造：new object
+ 委托实现

### 策略工厂违反开闭原则==》发射机制
  + 通过配置文件加载哪些策略类