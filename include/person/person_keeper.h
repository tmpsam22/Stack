#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H
#include <iostream>
// draft
// -----
// файл person_keeper.h содержит интерфейс объекта PersonKeeper

class PersonKeeper
{
private:
    PersonKeeper();
    ~PersonKeeper();
public:
    void someFoo() const { std::cout << "someFoo()\n"; }
    static PersonKeeper& CreateInstance();
};

#endif