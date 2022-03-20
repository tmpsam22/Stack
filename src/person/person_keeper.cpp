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

void PersonKeeper::writePersons(Stack<Person> stack, std::ofstream& ofile)
{
    doWritePersons(stack, ofile);
}

void PersonKeeper::writePersons(Stack<Person> stack, std::fstream& ofile)
{
    doWritePersons(stack, ofile);
}

void PersonKeeper::writePersons(Stack<Person> stack, const std::string& filename, std::ios_base::openmode openmode)
{
    std::string outname = filename.empty() ? "default_output.txt" : filename;
    std::ofstream ofile{outname, openmode};
    doWritePersons(stack, ofile);
}

Stack<Person> PersonKeeper::readPersons(std::ifstream& ifile)
{
    return doReadPersons(ifile);
}

Stack<Person> PersonKeeper::readPersons(std::fstream& ifile)
{
    return doReadPersons(ifile);
}

Stack<Person> PersonKeeper::readPersons(const std::string& filename)
{
    std::ifstream ifile{filename};
    return readPersons(ifile);
}

void PersonKeeper::doWritePersons(Stack<Person>& stack, std::ostream& ofile)
{
    if (!ofile)
    {
        throw std::runtime_error( "Got error while writing to the file: File is anccurate!" );
    }

    while (!stack.empty())
    {
        ofile << stack.top() << std::endl;
        stack.pop();
    }
}

Stack<Person> PersonKeeper::doReadPersons(std::istream& ifile)
{
    if (!ifile)
    {
        throw std::runtime_error( "Got error while writing to the file: File is anccurate!" );
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
    return stackPerson;
}

}   // namespace objects
}   // namespace custom