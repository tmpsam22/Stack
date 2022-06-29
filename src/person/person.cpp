#include <person/person.h>
#include <iostream>

/// @file person.cpp
/// @brief содержит реализации объекта person/person.h
namespace custom
{
namespace objects
{

Person::Person(first_name&& first_name_,
    second_name&& second_name_, patronymic&& patronymic_arg) :
        firstName_(std::move(first_name_.firstName_)),
        secondName_(std::move(second_name_.secondName_)),
        patronymic_(std::move(patronymic_arg.patronymic_))
{ }

Person::Person(const first_name& first_name_,
    const second_name& second_name_, const patronymic& patronymic_arg) :
        firstName_(first_name_.firstName_),
        secondName_(second_name_.secondName_),
        patronymic_(patronymic_arg.patronymic_)
{ }

const std::string& Person::getFirstName() const
{
    return firstName_;
}

const std::string& Person::getSecondName() const
{
    return secondName_;
}

const std::string& Person::getPatronymic() const
{
    return patronymic_;
}

void Person::setFirstName(const std::string& firstName)
{
    firstName_ = firstName;
}

void Person::setSecondName(const std::string& secondName)
{
    secondName_ = secondName;
}

void Person::setPatronymic(const std::string& patronymic)
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

}   // namespace objects
}   // namespace custom