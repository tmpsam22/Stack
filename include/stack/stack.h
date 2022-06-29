
#ifndef INCLUDE_STACK_H
#define INCLUDE_STACK_H

/// @file stack.h
/// @brief содержит реализацию класса Стек

#include <vector>
#include <algorithm>
#include <stack/exception.h>

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
     using is_not_same_type = typename std::enable_if_t<!std::is_same<second_type, typename std::decay<first_type>::type>::value>;


     /// @brief Вспомогательный класс для стека, отвечающий за узлы
     struct Node
     {
          /// @brief конструктор класса Node
          /// @param value инициализация нового узла значением value
          /// @param prev указатель на предыдущий узел
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

     /// @brief вспомогательная функция для копирования
     /// всех узлов из другого стека в новый
     /// @param rhs копируемый стек
     void copyFromTo(const Stack& rhs);

     /// @brief создает новый узел
     /// @param value инициализация нового узла значением value
     /// @param prev указатель на предыдущий узел
     /// @return новый узел
     /// @throw custom::exceptions::EStackException узел не создался из-за нехватки памяти
     template <typename U>
     Node* createNode(U&& value, Node* prev = nullptr);

public:

     /// @brief конструктор по умолчанию
     Stack();

     /// @brief деструктор
     ~Stack();

     /// @brief конструктор копирования
     Stack(const Stack&  stack);

     /// @brief конструктор перемещения
     Stack(Stack&& stack);

     /// @brief оператор присваивания
     Stack& operator=(const Stack& stack);

     /// @brief оператор перемещения
     Stack& operator=(Stack&& stack);

     /// @brief создает объект с одним узлом
     /// @param value значение узла
     template <typename U, typename = is_not_same_type<U, Stack>>
     explicit Stack(U&& value) :
          top_(createNode(std::forward<U>(value))), size_(1)
     { }

public:

     /// @brief Получение размерности стека
     /// @return размер стека
     size_t size() const;

     /// @brief Является ли стек пустым
     /// @return true - стек пустой, false - не пуст
     bool empty() const;

     /// @brief Добавление значения в стек
     /// @param value - значение (lvalue)
     void push(const T& value);

     /// @brief Добавление значения в стек
     /// @param value - значение (rvalue)
     void push(T&& value);

     /// @brief Удаление последнего значения из стека
     void pop();

     /// @brief Возвращает последнее значение из стека
     T& top();

     /// @brief Возвращает последнее значение из стека
     const T& top() const;
public:
     Node* top_ {};      // указатель(хвост) на узел
     size_t size_ {};    // размерность стека
};

template <typename T>
void Stack<T>::copyFromTo(const Stack& rhs) // вспомогательная функция для копирования
{
          Node* tmpNode_ =  rhs.top_;
          // данные из копируемого объекта, в данном  случае rhs
          // в целях сохранении последовательности
          // сначала записываются в динамический массив:
          std::vector<T> v{ rhs.size() };
          while (tmpNode_)
          {
               v.push_back(tmpNode_->value_);
               tmpNode_ = tmpNode_->prev_;
          }
          // записываем в текущий стек
          // в обратной последовательности из динамического массива:
          std::for_each(v.rbegin(), v.rend(),
                    [&](const auto& value) { push(value); });
}

template <typename T>
template <typename U>
typename Stack<T>::Node* Stack<T>::createNode(U&& value, Stack<T>::Node* prev)
{
     Node* tmpNode_ {};
     try
     {
          tmpNode_ = new Node(std::forward<U>(value), prev);
     }
     // при невозможности выделить память для узла - отлавливаем ошибку
     catch(std::bad_alloc& e)
     {
          // и выбрасываем исключение для нашего стека с соотвествующим сообщением:
          throw custom::exceptions::EStackException("Runtime error: bad_alloc, can't create a node in stack");
     }
     return tmpNode_;
}

template <typename T>
Stack<T>::Stack()
{
}

template <typename T>
Stack<T>::~Stack()
{
     while (size_)
     {
          pop();
     }
}

template <typename T>
Stack<T>::Stack(const Stack<T> & stack)
{
     copyFromTo(stack); // используется push(x) => size_ инкрементируется сам
}

template <typename T>
Stack<T>::Stack(Stack<T>&& rhs) : top_(rhs.top_), size_(rhs.size_)
{
     // обнуляем значения у копируемого объекта
     rhs.top_ = nullptr;
     rhs.size_ = 0;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs)
{
     if (this != &rhs)
     {
          return *this;
     }

     this->~Stack();  // очищаем память для выделенных узлов
     copyFromTo(rhs); // копируем значения у rhs
     return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& rhs)
{
     if (this != &rhs)
     {
          return *this;
     }

     this->~Stack(); // очищаем память для выделенных узлов

     // берем значения у объекта rhs
     top_ = rhs.top_;
     size_ = rhs.size_;

     // обнуляем значения у объекта rhs
     rhs.top_ = nullptr;
     rhs.size_ = 0;
     return *this;
}

template <typename T>
size_t Stack<T>::size() const
{
     return size_;
}

template <typename T>
bool Stack<T>::empty() const
{
     return top_ == nullptr;
}

template <typename T>
void Stack<T>::push(const T& value)
{
     top_ = createNode(value, top_);
     ++size_; // увеличиваем размерность
}

template <typename T>
void Stack<T>::push(T&& value)
{
     top_ = createNode(std::move(value), top_);
     ++size_; // увеличиваем размерность
}

template <typename T>
void Stack<T>::pop()
{
     if (top_)
     {
          Node* tmpNode = top_;
          top_ = top_->prev_;
          delete tmpNode; // очистить выделенный фрагмент памяти
          --size_; // уменьшаем размерность
     }
}

template <typename T>
T& Stack<T>::top()
{
     // вызов const функции top()
     return const_cast<T&>(static_cast<const Stack&>(*this).top());
}

template <typename T>
const T& Stack<T>::top() const
{
     if (top_)
     {
          return top_->value_; // возвращаем последний элемент, хранимый в хвосте
     }
     throw custom::exceptions::EStackEmpty("Runtime error: stack is empty. Called function top()");
}

}    // namespace objects
}    // namespace custom

#endif


