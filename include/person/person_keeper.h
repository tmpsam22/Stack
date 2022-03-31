#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H

#include <stack/stack.h>
#include <person/person.h>
#include <fstream>
#include <string>

/// @file person_keeper.h
/// @brief содержит интерфейс объекта PersonKeeper

namespace custom
{
namespace objects
{

class PersonKeeper
{
public:

    /// @brief Считывает ФИО из файла в стек
    /// @param input_filename название файла
    /// @return стек с записанными ФИО
    /// @throw std::runtime_error при неуспешном открытии объекта std::ifstream
    /// или при считывании некорректного символа
    Stack<Person> readPersons(const std::string& input_filename);

    /// @brief Считывает ФИО из файла в стек
    /// @param input_filename название файла
    /// @param ifile считывание из объекта fstream
    /// @return стек с записанными ФИО
    /// @throw std::runtime_error при некорректном std::fstream
    /// или при считывании некорректного символа
    Stack<Person> readPersons(std::fstream& ifile);

    /// @brief Считывает ФИО из файла в стек
    /// @param input_filename название файла
    /// @param считывание из объекта ifstream
    /// @return стек с записанными ФИО
    /// @throw std::runtime_error при некорректном std::ifstream
    /// или при считывании некорректного символа
    Stack<Person> readPersons(std::ifstream& ifile);

    /// @brief  Записывает из стека в файл,
    /// @param output_filename название файла
    /// @param openmode флаги открытия файла
    /// @throw std::runtime_error при неуспешном открытии объекта std::pfstream
    void writePersons(Stack<Person> stack, const std::string& output_filename="",
        std::ios_base::openmode openmode = std::ios_base::out);

    /// @brief  Записывает из стека в файл,
    /// @param ofile запись в объект std::ofstream
    /// @throw std::runtime_error при некорректном std::ofstream
    void writePersons(Stack<Person> stack, std::ofstream& ofile);

    /// @brief  Записывает из стека в файл,
    /// @param ofile запись в объект std::fstream
    /// @throw std::runtime_error при некорректном std::fstream
    void writePersons(Stack<Person> stack, std::fstream& ofile);

private:
    // Singleton - перемещение и копирование объекта запрещено
    PersonKeeper(const PersonKeeper&) = delete;
    PersonKeeper(PersonKeeper&&) = delete;
    PersonKeeper& operator=(const PersonKeeper&) = delete;
    PersonKeeper& operator=(PersonKeeper&&) = delete;

private:
    /// @brief вспомогательная функция, которая считывает ФИО из файла,
    /// используется в функциях readPersons
    Stack<Person> doReadPersons(std::istream&);

    /// @brief вспомогательная функция, которая записывает данные из стека в файл,
    /// используется в writePersons
    void doWritePersons(Stack<Person>& stack, std::ostream&);

private:
    // Singleton - создание объекта через функцию CreateInstance()
    PersonKeeper();
    ~PersonKeeper();

public:
    static PersonKeeper& CreateInstance();
};

}   // namespace objects
}   // namespace custom

#endif