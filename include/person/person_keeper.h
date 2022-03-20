#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H

#include <stack/stack.h>
#include <person/person.h>
#include <fstream>
#include <string>

// файл person_keeper.h содержит интерфейс объекта PersonKeeper

namespace custom
{
namespace objects
{

class PersonKeeper
{
public:

    /// * Считывает ФИО из файла в стек,
    // input_filename - его название
    Stack<Person> readPersons(const std::string& input_filename);
    // считывание из с объекта (i)fstream
    Stack<Person> readPersons(std::fstream& ifile);
    Stack<Person> readPersons(std::ifstream& ifile);

    /// * Записывает из стека в файл,
    // output_filename - его название
    // openmode - флаги открытия файла
    void writePersons(Stack<Person> stack, const std::string& output_filename="",
        std::ios_base::openmode openmode = std::ios_base::out);

    // запись в объект (o)fstream
    void writePersons(Stack<Person> stack, std::ofstream& ofile);
    void writePersons(Stack<Person> stack, std::fstream& ofile);

    PersonKeeper(const PersonKeeper&) = delete;
    PersonKeeper(PersonKeeper&&) = delete;
    PersonKeeper& operator=(const PersonKeeper&) = delete;
    PersonKeeper& operator=(PersonKeeper&&) = delete;

private:
    // считывает ФИО из файла
    // используется в функциях readPersons
    Stack<Person> doReadPersons(std::istream&);

    // Запись данных из стека в файл
    // используется в writePersons
    void doWritePersons(Stack<Person>& stack, std::ostream&);

private:
    PersonKeeper();
    ~PersonKeeper();

public:
    static PersonKeeper& CreateInstance();
};

}   // namespace objects
}   // namespace custom

#endif