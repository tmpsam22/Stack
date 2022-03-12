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

void PersonKeeper::writePersons(Stack<Person> stack, const std::string& filename, std::ios_base::openmode openmode)
{
    std::string outname = filename.empty() ? "default_output.txt" : filename;

    std::ofstream ofile(outname, openmode);
    if (!ofile)
    {
        throw std::runtime_error( "File: \"" + filename + "\" couldn't open!" );
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

    while (!ifile.eof())
    {
        Person tmpPerson;
        int count = 0;
        // * в файле ожидается ФИО
        while (count < 3)
        {
            std::string str{};
            ++count;
            char ch;

            while (ifile.get(ch) && !isspace(ch))
            {
                if (!isalpha(ch)) // символ не является буквой
                {
                    ifile.close();
                    throw std::runtime_error("Got unexpected symbol in file");
                }
                str += ch;
            }

            // считываем пробелы
            while (isspace(ifile.peek()))
            {
                ifile.get();
            }

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