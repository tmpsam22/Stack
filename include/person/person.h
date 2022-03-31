#ifndef PERSON_H
#define PERSON_H

/// @file person.h
/// @brief содержит интерфейс объекта Person
#include <string>

namespace custom
{
namespace objects
{

/// @brief класс хранит ФИО человека
class Person
{

public:
    struct first_name
    {
        explicit first_name(std::string&& firstName) : firstName_(std::move(firstName))
        {}
        explicit first_name(const std::string& firstName) : firstName_(firstName)
        {}
        std::string firstName_{};
    };

    struct second_name
    {
        explicit second_name(std::string&& secondName) : secondName_(std::move(secondName))
        {}
        explicit second_name(const std::string& secondName) : secondName_(secondName)
        {}
        std::string secondName_{};
    };

    struct patronymic
    {
        explicit patronymic(std::string&& patronymic) : patronymic_(std::move(patronymic))
        {}
        explicit patronymic(const std::string& patronymic) : patronymic_(patronymic)
        {}
        std::string patronymic_{};
    };

public:

    explicit Person(first_name&&, second_name&&, patronymic&&);
    explicit Person(const first_name&, const second_name&, const patronymic&);

    Person();
    virtual ~Person();

    const std::string& getFirstName() const;
    const std::string& getSecondName() const;
    const std::string& getPatronymic() const;

    void setFirstName(const std::string& firstName);
    void setSecondName(const std::string& secondName);
    void setPatronymic(const std::string& patronymic);

    friend std::ostream& operator<<(std::ostream& os, const Person& rhs);

private:
    std::string firstName_{};
    std::string secondName_{};
    std::string patronymic_{};
};

}   // namespace objects
}   // namespace custom
#endif
