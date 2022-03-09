#ifndef PERSON_H
#define PERSON_H

// файл person.h содержит интерфейс объекта Person

#include <string>

class Person
{

public:
    struct first_name
    {
        explicit first_name(const std::string& firstName) : firstName_(firstName)
        {}
        std::string firstName_{};
    };
    struct second_name
    {
        explicit second_name(const std::string& secondName) : secondName_(secondName)
        {}
        std::string secondName_{};
    };

    struct patronymic
    {
        explicit patronymic(const std::string& patronymic) : patronymic_(patronymic)
        {}
        std::string patronymic_{};
    };

public:

    explicit Person(const first_name&, const second_name&, const patronymic&);
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

#endif