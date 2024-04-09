#include "command.hpp"
int main() {
    Receiver receiver;
    Invoker invoker;

    // 创建具体命令并添加到调用者
    CommandInterface* command1 = new ConcreteCommand(receiver, 5);
    CommandInterface* command2 = new ConcreteCommand(receiver, 10);
    CommandInterface* command3 = new ConcreteCommand(receiver, 3);
    invoker.AddCommand(command1);
    invoker.AddCommand(command2);
    invoker.AddCommand(command3);

    // 执行命令
    invoker.ExecuteCommands();

    // 输出结果
    receiver.printTotalValue();  // 5 + 10 + 3 = 18

    
    // 再次输出结果
    receiver.printTotalValue();  // 0

    // 释放命令对象的内存
    delete command1;
    delete command2;
    delete command3;

    return 0;
}
