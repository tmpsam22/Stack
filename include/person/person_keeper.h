#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H

#include <custom_stack/stack.h>
#include <fstream>
#include <iostream>
// draft
// -----
// файл person_keeper.h содержит интерфейс объекта PersonKeeper

class PersonKeeper
{
public:

    //@todo
    template<typename T>
    static custom::objects::Stack<T> readPersons(const std::string& filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error( "File: \"" + filename + "\" couldn't open!" );
        }
        return custom::objects::Stack<T>();
    }

    template<typename T>
    static void writePersons(custom::objects::Stack<T>&)
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

#endif