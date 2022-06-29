#include <person/person_keeper.h>

/// @file person_keeper.cpp
/// @brief содержит реализации класса PersonKeeper
namespace custom
{
namespace objects
{

PersonKeeper& PersonKeeper::CreateInstance()
{
    static PersonKeeper PersonKeeper_; // определение статической переменной PersonKeeper
    return PersonKeeper_;
}

void PersonKeeper::writePersons(Stack<Person> stack, std::ofstream& ofile)
{
    doWritePersons(stack, ofile); // вызов приватной функции для записи в файл
}

void PersonKeeper::writePersons(Stack<Person> stack, std::fstream& ofile)
{
    doWritePersons(stack, ofile);  // вызов приватной функции для записи в файл
}

void PersonKeeper::writePersons(Stack<Person> stack, const std::string& filename, std::ios_base::openmode openmode)
{
    // если имя файла отсутствует, то определяем его сами
    std::string outname = filename.empty() ? "default_output.txt" : filename;
    std::ofstream ofile{outname, openmode};
    doWritePersons(stack, ofile); // вызов приватной функции для записи в файл
}

Stack<Person> PersonKeeper::readPersons(std::ifstream& ifile)
{
    return doReadPersons(ifile); // вызов приватной функции для считывания из файла
}

Stack<Person> PersonKeeper::readPersons(std::fstream& ifile)
{
    return doReadPersons(ifile); // вызов приватной функции для считывания из файла
}

Stack<Person> PersonKeeper::readPersons(const std::string& filename)
{
    std::ifstream ifile{filename}; // открыть файл
    return readPersons(ifile); //  вызов приватной функции для считывания из файла
}

void PersonKeeper::doWritePersons(Stack<Person>& stack, std::ostream& ofile)
{
    // объект ostream является невалидным
    // запись не возможна
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
    // объект istream является невалидным
    // считывание невозможно
    if (!ifile)
    {
        throw std::runtime_error( "Got error while writing to the file: File is anccurate!" );
    }

    // определяем стек для хранения ФИО людей
    Stack<Person> stackPerson;

    while (!ifile.eof()) // пока не достигли конца файла
    {
        Person tmpPerson;
        int count = 0;
        // * в файле ожидается ФИО
        // при count = 1 - фамилия
        // при count = 2 - имя
        // при count = 3 - отчество
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
                str += ch; // запись прочитанных символов
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
                    stackPerson.push(tmpPerson); // считали отчество, следовательно можем добавить данные человека в стек
                    break;
                default:
                    throw std::runtime_error("Something is wrong in readPersons");
            }
        }
    }
    return stackPerson; // возращаем стек
}

}   // namespace objects
}   // namespace custom