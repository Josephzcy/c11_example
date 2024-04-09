### 限流器框架
1. 项目背景
2. 需求背景
3. 需求分析
  + 功能性需求：用户用例和测试驱动开发的思想
  + 非功能性需求：
    + 易用性：方便的切换不同的限流算法
    + 易集成：
    + 扩展性、灵活性：
      + 灵活扩展各种限流算法
      + 支持不同格式
      + 支持不同数据源
    + 性能方面：低延迟
    + 容错性高
1. 重点：开发套路
 + 分析：需求梳理
 + 设计：模块分析、模块设计
    2. 限流规则
    3. 限流算法
    4. 限流模式
    5. 集成使用：低入侵，与业务代码松耦合
 + 实现
  + 用到的编程思想
  + 设计原理或者设计思想
  + 最小原型代码MVP
    1. 划分职责识别类
    2. 定义属性和方法
    3. 类直接交互
    4. 组装类并提供执行入口
  + v1版存在的问题，v2版改进 
    + 集成使用模块：最顶层类，组装其他类并提供执行入口；不应该涉及到业务代码
    + 扩展类性能点
      + 配置文件的路径不支持配置、格式只支持一种
      + 限流规则支持一种