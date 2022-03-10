#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H

#include <custom_stack/stack.h>
#include <fstream>
#include <person/person.h>
#include <string>
// draft
// -----
// файл person_keeper.h содержит интерфейс объекта PersonKeeper
namespace custom
{
namespace objects
{

class PersonKeeper
{
public:
    // draft
    /* t e */
    static Stack<Person> readPersons(const std::string& input_filename);
    /* add flags to out */
    static void writePersons(Stack<Person> stack, const std::string& output_filename="");

    PersonKeeper(const PersonKeeper&) = delete;
    PersonKeeper(PersonKeeper&&) = delete;
    PersonKeeper& operator=(const PersonKeeper&) = delete;
    PersonKeeper& operator=(PersonKeeper&&) = delete;

private:
    PersonKeeper();
    ~PersonKeeper();

public:
    static PersonKeeper& CreateInstance();
};

}   // namespace objects
}   // namespace custom

#endif