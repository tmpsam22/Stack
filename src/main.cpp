#include <iostream>
#include <stack/stack.h>
#include <person/person_keeper.h>
#include <person/person.h>
#include <memory>

using namespace custom::objects;


// функция, которая выводит значения в скопированном стеке
template <typename T>
void display(Stack<T> stack, const std::string& message)
{
     std::cout << message << std::endl;
     while(stack.size())
     {
          std::cout << stack.top() << ' ';
          stack.pop();
     }
     std::cout << std::endl;
}

void test()
{
     std::cout << "----------------------------" << std::endl;
     std::cout << "EXCEPTION TEST" << std::endl;
     try
     {
          Stack<int> widget_empty;
          widget_empty.top(); // ожидается исключение EStackException
     }
     catch(custom::exceptions::EStackException& e)
     {
          // вывод : Runtime error: stack is empty. Called function top()
          std::cerr << e.what() << std::endl;
     }
     std::cout << "----------------------------" << std::endl;
     std::cout << "PUSH TEST" << std::endl;
     //Инициализация стека другим стеком.
     Stack<int> widget_first;
     display(widget_first, "widget_first");
     std::vector<int> values{ 1, 2, 4, 5};
     for (auto& value : values)
     {
          widget_first.push(value);
     }
     display(widget_first, "widget_first");

     std::cout << "----------------------------" << std::endl;
     std::cout << "COPY CTOR TEST" << std::endl;
     Stack<int> widget_second = widget_first; // глубокое копирование:

     // все элементы копируются в новые динамические фрагменты
     display(widget_first, "widget first");
     display(widget_second, "widget second");
     std::cout << "----------------------------" << std::endl;
     std::cout << "ASSIGNMENT OPERATOR TEST" << std::endl;
     //Присваивание стека:
     Stack<int> widget_third{ 99 };
     display(widget_third, "widget_third");
     Stack<int> widget_fourth{ 100 } ;

     widget_third =  widget_fourth; // значение последнего элемента равно теперь 100

     display(widget_third, "widget_third");
     display(widget_fourth, "widget_fourth");
     std::cout << "----------------------------" << std::endl;
     // конструктор перемещения
     std::cout << "CTOR WITH MOVE SEMANTICS TEST" << std::endl;
     Stack<int> widget_fivth = std::move(widget_first);
     display(widget_fivth, "widget_fivth");
     display(widget_first, "widget_first");
     std::cout << "----------------------------" << std::endl;
     // оператор присваивания с перемещением
     std::cout << "ASIGNMENT OPERATOR WITH MOVE SEMATICS TEST" << std::endl;
     Stack<int> widget_sixth { 120 };
     display(widget_sixth, "widget_sixth");
     widget_sixth = std::move(widget_fivth);
     display(widget_sixth, "widget_sixth");
     display(widget_fivth, "widget_fivth");
     // вывод размерности стеков
     std::cout << "SIZES:\n";
     std::cout << "widget_sixth:\t" << widget_sixth.size() << std::endl;
     std::cout << "widgex_fivth:\t" << widget_fivth.size() << std::endl;

     // проверяем на пустоту стека
     std::cout << "is widget_fivth EMPTY:\t" << std::boolalpha << widget_fivth.empty() << std::endl;

     std::cout << "----------------------------" << std::endl;
     std::cout << "TOP from widget_sixth is:\t " << widget_sixth.top() << std::endl;
     widget_sixth.pop();
     display(widget_sixth, "after POP values in widget_sixth:");
     std::cout << "SIZE of widget_sixth: " << widget_sixth.size() << std::endl;
}

int main(int argc, const char** argv) try
{
     // достаточно запустить скрипт start_build.sh, который собирает проект
     // и запускает исполняемый файл
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
