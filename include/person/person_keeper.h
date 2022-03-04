#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H

#include <custom_stack/stack.h>
#include <fstream>
// draft
// -----
// файл person_keeper.h содержит интерфейс объекта PersonKeeper

class PersonKeeper
{

private:
    PersonKeeper();
    ~PersonKeeper();
/*
    @todo
    template<typename T>
    custom::objects::Stack<T> readPersons();

    template<typename T>
    void writePersons(custom::objects::Stack<T>&);
*/
    PersonKeeper(const PersonKeeper&) = delete;
    PersonKeeper& operator=(const PersonKeeper&) = delete;
public:
    static PersonKeeper& CreateInstance();
};

#endif