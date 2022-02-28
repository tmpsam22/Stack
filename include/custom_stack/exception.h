#ifndef CUSTOM_STACK_EXCEPTION_H
#define CUSTOM_STACK_EXCEPTION_H

//файл содержит exception-объекты custom_stack/stack.h

#include <string>

namespace custom
{
namespace exceptions
{

class EStackException
{
public:

     EStackException() : strerror_("Runtime error: stack default error")
     { }

     explicit EStackException(const std::string& strerror) : strerror_(strerror)
     { }

     explicit EStackException(const char* strerror) : strerror_(strerror)
     { }

     EStackException(const EStackException& rhs) : strerror_(rhs.strerror_)
     { }

     EStackException& operator=(const EStackException& rhs)
     {
          strerror_ = rhs.strerror_;
          return *this;
     }

     virtual ~EStackException()
     { }

     virtual const char* what() const noexcept
     {
          return strerror_.c_str();
     }

private:
     std::string strerror_;
};


struct EStackEmpty : EStackException
{
     EStackEmpty() : EStackException("Runtime error: stack is empty")
     { }

     explicit EStackEmpty(const std::string& strerror): EStackException(strerror)
     { }

     explicit EStackEmpty(const char * strerror) : EStackException(strerror)
     { }

     ~EStackEmpty() override
     { }
};

} // namespace exceptions
} // namespace custom

#endif