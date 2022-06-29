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
        Пусть имеется человек с именем A, с фамилией B и с отчеством B.

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
    */

    /// @brief вспомогательный класс отвечающий за имя человека
    struct first_name
    {
        /// конструкторы

        /// @param firstName - имя человека
        explicit first_name(std::string&& firstName) : firstName_(std::move(firstName))
        {}

        /// @param firstName - имя человека
        explicit first_name(const std::string& firstName) : firstName_(firstName)
        {}

        // имя
        std::string firstName_{};
    };

    /// @brief вспомогательный класс отвечающий за фамилию человека
    struct second_name
    {
        /// конструкторы

        /// @param secondName - фамилия человека
        explicit second_name(std::string&& secondName) : secondName_(std::move(secondName))
        {}

        /// @param secondName - фамилия человека
        explicit second_name(const std::string& secondName) : secondName_(secondName)
        {}

        // фамилия
        std::string secondName_{};
    };

    /// @brief вспомогательный класс отвечающий за отчество человека
    struct patronymic
    {
        /// конструкторы
        /// @param patronymic - отчество человека
        explicit patronymic(std::string&& patronymic) : patronymic_(std::move(patronymic))
        {}

        /// @param patronymic - отчество человека
        explicit patronymic(const std::string& patronymic) : patronymic_(patronymic)
        {}

        // отчество
        std::string patronymic_{};
    };

public:

    /// @brief конструктор
    /// фио записаны в виде вспомогательных классов,
    /// определенных выше
    /// @param first_name - имя человека
    /// @param second_name - фамилия человека
    /// @param patronymic - отчество человека
    explicit Person(
        first_name&& first_name,
        second_name&& second_name,
        patronymic&& patronymic
    );

    /// @brief конструктор
    /// фио записаны в виде std::string
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
