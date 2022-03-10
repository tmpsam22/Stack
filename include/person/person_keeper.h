#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H

#include <custom_stack/stack.h>
#include <fstream>
#include <person/person.h>

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

    //@todo
    static Stack<Person> readPersons(const std::string& filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error( "File: \"" + filename + "\" couldn't open!" );
        }
        return Stack<Person>();
    }

    static void writePersons(Stack<Person>&)
    {
    }

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