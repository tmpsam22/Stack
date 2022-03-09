#include <iostream>
#include <custom_stack/stack.h>
#include <person/person_keeper.h>
#include <person/person.h>
#include <memory>

using custom::objects::Stack;
constexpr auto filename = "names.txt";

template <typename T>
void display(Stack<T> stack)
{
     while(stack.size())
     {
          std::cout << stack.top() << '\t';
          stack.pop();
     }
     std::cout << std::endl;
}

void test()
{
     PersonKeeper& PersonKeeper_ = PersonKeeper::CreateInstance();
     PersonKeeper_.readPersons<int>(filename);
     Person person(Person::first_name("S"), Person::second_name("T"),
          Person::patronymic("U"));
     std::cout << person << std::endl;
}

int main() try
{
     test();
     return EXIT_SUCCESS;
}
catch(custom::exceptions::EStackException& e)
{
     std::cerr << e.what() << std::endl;
     return EXIT_FAILURE;
}
catch(std::exception&e)
{
     std::cerr << e.what() << std::endl;
     return EXIT_FAILURE;
}
catch(...)
{
     std::cerr << "Got unknown error\n";
     return EXIT_FAILURE;
}
