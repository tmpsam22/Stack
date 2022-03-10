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

void PersonKeeper::writePersons(Stack<Person> stack, const std::string& filename)
{
    std::string outname = filename.empty() ? "default_output.txt" : filename;
    std::ofstream ofile(outname);
    if (!ofile)
    {
        throw std::runtime_error("Can't open file");
    }
    while (!stack.empty())
    {
        ofile << stack.top() << std::endl;
        stack.pop();
    }
    ofile.close();
}

Stack<Person> PersonKeeper::readPersons(const std::string& filename)
{
    std::ifstream ifile(filename);
    if (!ifile.is_open())
    {
        throw std::runtime_error( "File: \"" + filename + "\" couldn't open!" );
    }

    Stack<Person> stackPerson;
    /* test me */
    /* add err */
    while (ifile)
    {
        std::string str{};
        int count = 0;
        Person tmpPerson;
        while (count < 3 && ifile >> str)
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
    ifile.close();
    return stackPerson;
}

}   // namespace objects
}   // namespace custom