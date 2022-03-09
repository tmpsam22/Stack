#include <person/person.h>
#include <iostream>

// файл person.cpp содержит реализации объекта person/person.h

Person::Person(const first_name& first_name_,
    const second_name& second_name_, const patronymic& patronymic_arg) :
        firstName_(first_name_.firstName_),
        secondName_(second_name_.secondName_),
        patronymic_(patronymic_arg.patronymic_)
{ }

Person::~Person()
{ }

inline const std::string& Person::getFirstName() const
{
    return firstName_;
}

inline const std::string& Person::getSecondName() const
{
    return secondName_;
}

inline const std::string& Person::getPatronymic() const
{
    return patronymic_;
}

inline void Person::setFirstName(const std::string& firstName)
{
    firstName_ = firstName;
}

inline void Person::setSecondName(const std::string& secondName)
{
    secondName_ = secondName;
}

inline void Person::setPatronymic(const std::string& patronymic)
{
    patronymic_ = patronymic;
}

std::ostream& operator<<(std::ostream& os, const Person& person_)
{
    os << person_.firstName_
        << ' ' << person_.secondName_
        << ' ' << person_.patronymic_;
    return os;
}