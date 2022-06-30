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

    /// @brief вспомогательные классы в целях обеспечения правильной вставки пользователем
    /// имени, фамилии и отчества
    /*
        Как пример:
        Пусть имеется человек с именем A, с фамилией B и с отчеством C.

        Person student(Person::first_name{"A"},
            Person::second_name{"B"},
            Person::patronymic{"C"}
        );
        Такой запись помогает пользователю ясно видеть какая последовательность
        ожидается в конструкторе
        Из-за своей невнимательности он может ошибочно записать данные человека в таком виде:
        Person student("B", "A", "C");
        Где имени присваивается фамилия, а фамилии - имя.
        Данные записаны ошибочно.

        Ранее конструктор принимал вспомогательные классы типа rvalue:
        Person(first_name&&, second_name&&, patronymic&&);
        что было действительно излишним, т.к. в таком конструкторе нет необходимости:
        использовать эти классы вне объекта Person мало кто захочет.
        а если он и хочет передать в Person - придется приводить к rvalue.
        также нужно отметить, что конструктор с аргументами const& могут также принимать rvalue значения
        ... в общем, поэтому такой конструктор Я убрал, класс Person стал компактнее.
    */

    /// @brief вспомогательный класс отвечающий за имя человека
    struct first_name
    {
        /// конструктор
        /// @param firstName - имя человека
        explicit first_name(const std::string& firstName) : firstName_(firstName)
        {}

        // имя
        std::string firstName_{};
    };

    /// @brief вспомогательный класс отвечающий за фамилию человека
    struct second_name
    {
        /// конструктор

        /// @param secondName - фамилия человека
        explicit second_name(const std::string& secondName) : secondName_(secondName)
        {}

        // фамилия
        std::string secondName_{};
    };

    /// @brief вспомогательный класс отвечающий за отчество человека
    struct patronymic
    {
        /// конструктор

        /// @param patronymic - отчество человека
        explicit patronymic(const std::string& patronymic) : patronymic_(patronymic)
        {}

        // отчество
        std::string patronymic_{};
    };

public:

    /// @brief конструктор
    /// @param first_name - имя человека
    /// @param second_name - фамилия человека
    /// @param patronymic - отчество человека

    explicit Person(
        const first_name& first_name,
        const second_name& second_name,
        const patronymic& patronymic
    );

    /// @brief конструктор по умолчанию
    Person() = default;

    /// @brief деструктор по умолчанию
    virtual ~Person() = default;

    /// @brief получить имя человека
    /// @return имя человека
    const std::string& getFirstName() const;

    /// @brief получить фамилию человека
    /// @return фамилия человека
    const std::string& getSecondName() const;

    /// @brief получить имя человека
    /// @return имя
    const std::string& getPatronymic() const;

    /// @brief записать имя
    /// @param firstName имя человека
    void setFirstName(const std::string& firstName);

    /// @brief записать фамилию
    /// @param firstName фамилия человека
    void setSecondName(const std::string& secondName);

    /// @brief записать отчество
    /// @param firstName отчество человека
    void setPatronymic(const std::string& patronymic);

    // вывод в stdout имя, фамилии и отчества человека
    friend std::ostream& operator<<(std::ostream& os, const Person& rhs);

private:

    // имя человека
    std::string firstName_{};

    // фамилия человека
    std::string secondName_{};

    // отчество человека
    std::string patronymic_{};
};

}   // namespace objects
}   // namespace custom
#endif
