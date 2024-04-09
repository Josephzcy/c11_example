#include <iostream>
#include <type_traits>
#include<tuple>
#include<string>
template <typename T>
class function_traits;  // declear

//特化
template <typename Ret, typename... Args>
class function_traits<Ret(Args...)> {
 public:
  enum { arity = sizeof...(Args) };
  using FuncType = Ret(Args...);
  using FuncPtr = Ret (*)(Args...);
  // using RetType = typename std::result_of<Ret(Args...)>::type;
  
  template<std::size_t I>
  using ArgType = typename std::tuple_element<I, std::tuple<Args...>>::type;
 
};
template<typename T>
void PrintType(){
  std::cout << "type:"<< typeid(T).name() << std::endl;
}