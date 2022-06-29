#include <iostream>
#include <stack/stack.h>
#include <person/person_keeper.h>
#include <person/person.h>
#include <memory>

using namespace custom::objects;


// функция, которая выводит значения в скопированном стеке
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
     std::fstream file(in_filename); // открываем файл на чтение
     // получаем единственный экземляр PersonKeeper и с помощью него считываем из файла данные в стек

     auto stackPersons = PersonKeeper::CreateInstance().readPersons(file);
     // данные в полученном стеке выводим в консоль

     display(stackPersons);
     // записываем полученные данные в файл с помощью ед. экзмепляра PersonKeeper
     PersonKeeper::CreateInstance().writePersons(stackPersons, file);
}

int main(int argc, const char** argv) try
{
     // достаточно запустить скрипт start_build.sh, который собирает проект
     // и запускает исполняемый файл с валидными входными данными
     // ожидаем:
     //./first_lab names.txt fromstack.txt
     // 1 аргумент - имя файла для открытия
     // 2 аргумент - для записи
     if (argc != 3)
     {
          return EXIT_FAILURE;
     }

     test(argv[1], argv[2]); // тестируем
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
