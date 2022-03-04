#include <iostream>
#include <custom_stack/stack.h>
#include <person/person_keeper.h>
#include <memory>

using custom::objects::Stack;

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
     std::cout << "Hello world!\n";
     PersonKeeper& PersonKeeper_ = PersonKeeper::CreateInstance();
     PersonKeeper_.someFoo();
}

int main() try
{
     test();
     return EXIT_SUCCESS;
}
catch (custom::exceptions::EStackEmpty& e)
{
     std::cerr << e.what() << std::endl;
     return EXIT_FAILURE;
}
catch(custom::exceptions::EStackException& e)
{
     std::cerr << e.what() << std::endl;
     return EXIT_FAILURE;
}
catch(...)
{
     std::cerr << "Got unknown error\n";
     return EXIT_FAILURE;
}