
#ifndef INCLUDE_STACK_H
#define INCLUDE_STACK_H

// файл stack.h содержит реализацию класса Стек

#include <vector>
#include <algorithm>
#include <custom_stack/exception.h>

namespace custom
{
namespace objects
{

template <typename T>
class Stack final
{
private:

     // алиас для использования явного конструктора для объектов, которые не являются Stack//Node
     // * чтобы должным образом отрабатывала перегрузка конструкторов
     template <typename first_type, typename second_type>
     using is_not_same_type = typename std::enable_if<!std::is_same<second_type, typename std::decay<first_type>::type>::value>::type;

     struct Node
     {
          template <typename U, typename = is_not_same_type<U, Node>>
          explicit Node(U&& value, Node* prev = nullptr)
               : value_(std::forward<U>(value)), prev_(prev)
          { }

          Node()
          { }

          ~Node()
          { }

          T value_ {};        // значение в узле
          Node* prev_ {};     // указатель на предыдущий узел
     };

private:
     // копирует значения в стеке из одного в другой
     void copyFromTo(const Stack& rhs)
     {
          Node* tmpNode_ =  rhs.top_;
          std::vector<T> v;
          v.reserve(rhs.size());

          while(tmpNode_)
          {
               v.push_back(tmpNode_->value_);
               tmpNode_ = tmpNode_->prev_;
          }
          std::for_each(v.rbegin(), v.rend(),
                    [&](const auto& value) { push(value); });
     }
     // создает новый узел
     template <typename U>
     Node* createNode(U&& value, Node* prev = nullptr)
     {
          Node* tmpNode_ = new (std::nothrow) Node(std::forward<U>(value), prev);

          if (!tmpNode_)      // tmpNode_ = nullptr, если узел не создался
          {
               throw custom::exceptions::EStackException("Runtime error: bad_alloc");
          }
          return tmpNode_;
     }

public:
     Stack()
     { }

     ~Stack()
     {
          while(size_)
          {
               pop();
          }
     }

     Stack(const Stack& rhs)
     {
          copyFromTo(rhs); // используется push(x) => size_ инкрементируется
     }

     Stack(Stack&& rhs) : top_(rhs.top_), size_(rhs.size_)
     {
          rhs.top_ = nullptr;
          rhs.size_ = 0;
     }

     // конструирует объект с одним узлом
     template <typename U, typename = is_not_same_type<U, Stack>>
     explicit Stack(U&& value) :
          top_(createNode(std::forward<U>(value))), size_(1)
     { }

     Stack& operator=(const Stack& rhs)
     {
          if (this != &rhs)
          {
               return *this;
          }

          this->~Stack();
          copyFromTo(rhs);
          return *this;
     }

     Stack& operator=(Stack&& rhs)
     {
          if (this != &rhs)
          {
               return *this;
          }

          this->~Stack();
          top_ = rhs.top_;
          size_ = rhs.size_;
          rhs.top_ = nullptr;
          rhs.size_ = 0;
          return *this;
     }

public:
     size_t size() const
     {
          return size_;
     }

     bool empty() const
     {
          return top_ == nullptr;
     }

     void push(const T& value)
     {
          top_ = createNode(value, top_);
          ++size_;
     }

     void push(T&& value)
     {
          top_ = createNode(std::move(value), top_);
          ++size_;
     }

     void pop()
     {
          if(top_)
          {
               Node* tmpNode = top_;
               top_ = top_->prev_;
               delete tmpNode;
               --size_;
          }
     }

     T& top()
     {
          return const_cast<T&>(static_cast<const Stack&>(*this).top());
     }

     const T& top() const
     {
          if(top_)
          {
               return top_->value_;
          }
          throw custom::exceptions::EStackEmpty("Runtime error: stack is empty. Called function top()");
     }

public:
     Node* top_ {};      // указатель(хвост) на узел
     size_t size_ {};    // размерность стека
};

} // namespace objects
} // namespace custom

#endif


