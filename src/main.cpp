#include <iostream>
#include <stack/stack.h>
#include <person/person_keeper.h>
#include <person/person.h>
#include <memory>

using namespace custom::objects;

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

void test(const std::string& in_filename, const std::string& out_filename)
{
     PersonKeeper& PersonKeeper_ = PersonKeeper::CreateInstance();
     auto stackPersons = PersonKeeper_.readPersons(in_filename);
     PersonKeeper_.writePersons(stackPersons, out_filename);
}

int main(int argc, const char** argv) try
{
     if (argc != 3)
     {
          return EXIT_FAILURE;
     }
     test(argv[1], argv[2]); //input, output
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
