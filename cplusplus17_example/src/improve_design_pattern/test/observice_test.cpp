#include "observice.hpp"
int main(int argc, char* argv[]) {
  SubjectInterface sub;
  ObserverInterface* a = new ConcreteObserverA();

  ObserverInterface* b = new ConcreteObserverB();


  sub.attach(a);
  sub.attach(b);
  // sub.notify();
  
  Event<std::function<void(int,int)>> my_event;

  stA t;

  my_event.Register([](int a, int b) { std::cout << a + b << std::endl; });
  my_event.Register(print);



  my_event.Register(std::bind(&stA::printA, &t,std::placeholders::_1,std::placeholders::_2));


  my_event.Notify(1,2);



  return 0;
}