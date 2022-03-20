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
          std::cout << stack.top() << '\n';
          stack.pop();
     }
}

void test(const std::string& in_filename, const std::string& out_filename)
{
     PersonKeeper& PersonKeeper_ = PersonKeeper::CreateInstance();
     std::fstream file(in_filename);
     auto stackPersons = PersonKeeper_.readPersons(file);
     display(stackPersons);
     PersonKeeper_.writePersons(stackPersons, file);
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
