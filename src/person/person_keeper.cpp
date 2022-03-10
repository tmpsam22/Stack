#include <person/person_keeper.h>

// файл person_keeper.cpp содержит реализации класса PersonKeeper

namespace custom
{
namespace objects
{

PersonKeeper::PersonKeeper()
{ }

PersonKeeper::~PersonKeeper()
{ }

PersonKeeper& PersonKeeper::CreateInstance()
{
    static PersonKeeper PersonKeeper_;
    return PersonKeeper_;
}

void PersonKeeper::writePersons(Stack<Person>&)
{ }

Stack<Person> PersonKeeper::readPersons(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error( "File: \"" + filename + "\" couldn't open!" );
    }

    Stack<Person> stackPerson;
    /* test me */
    while (file)
    {
        std::string str{};
        int count = 0;
        Person tmpPerson;
        while (count < 3 && file >> str)
        {
            ++count;
            switch (count)
            {
                case 1:
                    tmpPerson.setSecondName(str);
                    break;
                case 2:
                    tmpPerson.setFirstName(str);
                    break;
                case 3:
                    tmpPerson.setPatronymic(str);
                    stackPerson.push(tmpPerson);
                    break;
                default:
                    throw std::runtime_error("Something is wrong in readPersons");
            }
        }
    }
    return stackPerson;
}

}   // namespace objects
}   // namespace custom