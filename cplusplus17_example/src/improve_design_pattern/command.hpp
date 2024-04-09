// 命令类爆炸的问题
// 解决方案：参数化解决
   //! 模板 
   //! 依赖注入 + 委托 :将命令的请求封装成函数、可调用对象或者类对象
//todo: 将请求的发送 和接收解耦


#include <iostream>
#include <vector>

class Receiver {
private:
    int totalValue;

public:
    Receiver() : totalValue(0) {}

    void addValue(int value) {
        totalValue += value;
        std::cout << "Receiver: Added value: " << value << std::endl;
    }

    void subtractValue(int value) {
        totalValue -= value;
        std::cout << "Receiver: Subtracted value: " << value << std::endl;
    }

    void printTotalValue() {
        std::cout << "Receiver: Total value: " << totalValue << std::endl;
    }
};
// 命令接口
class CommandInterface {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// 具体命令
class ConcreteCommand : public CommandInterface {
private:
    Receiver& receiver;
    int value;

public:
    ConcreteCommand(Receiver& recv, int val) : receiver(recv), value(val) {}

    void execute() override {
        receiver.addValue(value);
    }

    void undo() override {
        receiver.subtractValue(value);
    }
};




// 调用者
class Invoker{
  private:
   std::vector<CommandInterface*> command_vec_;

  public:
   void AddCommand(CommandInterface* command) {
     std::cout << "add command" << std::endl;
     command_vec_.emplace_back(command);
   }

   void ExecuteCommands() {
     for (auto command : command_vec_) {
       command->execute();
     }
   }
};
