#ifndef CUSTOM_STACK_EXCEPTION_H
#define CUSTOM_STACK_EXCEPTION_H

/// @file exception.h
/// @brief содержит exception-объекты custom_stack/stack.h

#include <string>

namespace custom
{
namespace exceptions
{

/// @brief общий класс исключений для стека
class EStackException
{
public:

     /// @brief конструктор по умолчанию
     // сообщение об ошибке по умолчанию  - "Runtime error: stack default error"
     EStackException() : strerror_("Runtime error: stack default error")
     { }

     /// @brief конструктор
     /// @param sterror - сообщение об ошибке для записи
     explicit EStackException(const std::string& strerror) : strerror_(strerror)
     { }

     /// @brief конструктор
     /// @param sterror - сообщение об ошибке для записи
     explicit EStackException(const char* strerror) : strerror_(strerror)
     { }

     /// @brief конструктор копирования
     /// @param rhs - объект EStackException для копирования
     EStackException(const EStackException& rhs) : strerror_(rhs.strerror_)
     { }

     /// @brief оператор присваивания
     /// @param rhs - объект EStackException для присваивания
     EStackException& operator=(const EStackException& rhs)
     {
          strerror_ = rhs.strerror_;
          return *this;
     }

     /// @brief деструктор
     virtual ~EStackException()
     { }

     /// @brief вывести сообщение об ошибке
     /// @param сообщение об ошибке
     virtual const char* what() const noexcept
     {
          return strerror_.c_str();
     }

private:

     // содержит сообщение об ошибке
     std::string strerror_;
};

/// @brief класс ошибка, что стек пуст
struct EStackEmpty : EStackException
{
     /// @brief конструктор по умолчанию
     /// по умолчанию записывается сообщение что стек пуст
     EStackEmpty() : EStackException("Runtime error: stack is empty")
     { }

     /// @brief конструктор
     /// @param sterror - сообщение об ошибке для записи
     explicit EStackEmpty(const std::string& strerror): EStackException(strerror)
     { }

     /// @brief конструктор
     /// @param sterror - сообщение об ошибке для записи
     explicit EStackEmpty(const char * strerror) : EStackException(strerror)
     { }

     /// @brief деструктор
     ~EStackEmpty() override
     { }
};

}    // namespace exceptions
}    // namespace custom

#endif