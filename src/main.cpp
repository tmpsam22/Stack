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

void display_test(const std::string& message)
{
     std::cout << "--------------TEST--------------" << std::endl;
     std::cout << message << std::endl;
}

void test()
{
     const std::string out_filename{ "../default_output.txt" };
     const std::string valid_file{"../valid_names.txt"};
     const std::string invalid_file{"../invalid_symbol.txt"};
     display_test("EXPECT INVALID SYMBOL IN FILE");
     try {
          // создается статический объект PersonKeeper
          // извлекаем ФИО из файла
          PersonKeeper::CreateInstance().readPersons(invalid_file);
          // ожидается исключение runtime_error с сообщением об ошибки:
          // Got unexpected symbol in file
     } catch( std::exception& e) {
          std::cerr << e.what() << std::endl;
     }

     // valid data - это ФИО

     display_test("READING valid data, arg is string");

     // Считываем валидные данные (Ожидается ФИО) из файла:
     auto stack = PersonKeeper::CreateInstance().readPersons(valid_file);
     display(stack);

     display_test("READING valid data, arg is ifstream");
     std::ifstream ifile {valid_file};
     stack = PersonKeeper::CreateInstance().readPersons(ifile);
     display(stack);

     display_test("READING valid data, arg is fstream");
     std::fstream file {valid_file};
     stack = PersonKeeper::CreateInstance().readPersons(file);
     display(stack);

     display_test("WRITING valid data to file, arg is string");
     Stack<Person> stack_w
     {
          Person (
               Person::first_name{"A"},
               Person::second_name{"B"},
               Person::patronymic{"C"}
          )
     };

     PersonKeeper::CreateInstance().writePersons(stack_w, out_filename);
     std::cout << "Checking result:\n";
     display(
          PersonKeeper::CreateInstance().readPersons(out_filename)
     );

     display_test("WRITING valid data to file, arg is fstream");
     std::fstream file_w {out_filename};
     PersonKeeper::CreateInstance().writePersons(stack_w, file_w);
     std::cout << "Checking result:\n";
     display(
          PersonKeeper::CreateInstance().readPersons(out_filename)
     );

     display_test("WRITING valid data to file, arg is ofstream");
     std::ofstream ofile {out_filename};
     PersonKeeper::CreateInstance().writePersons(stack_w, ofile);
     std::cout << "Checking result:\n";
     display(
          PersonKeeper::CreateInstance().readPersons(out_filename)
     );

     std::cout << "\nTesting class Person\n";
     auto& person = stack_w.top(); // получили объект Person для тестирования
     display_test("Getting first name from Person");
     std::cout << "first name: "<< person.getFirstName() << std::endl;
     display_test("Getting second name from Person");
     std::cout << "second name: " << person.getSecondName() << std::endl;
     display_test("Getting patronymic from Person");
     std::cout << "third name: "<< person.getPatronymic() << std::endl;
     display_test("Setting \"X\" first name to Person");
     person.setFirstName("X");

     std::cout << "now first name: "<< person.getFirstName() << std::endl;
     display_test("Setting \"Y\" second name to Person");

     person.setSecondName("Y");
     std::cout << "now second name: " << person.getSecondName() << std::endl;

     display_test("Setting \"Z\" patronymic to Person");
     person.setPatronymic("Z");
     std::cout << "now third name: "<< person.getPatronymic() << std::endl;

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
