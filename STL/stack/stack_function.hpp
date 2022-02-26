#ifndef FT_STACK_FUNCTION
# define FT_STACK_FUNCTION

#include "stack.hpp"

namespace ft
{
    /* Говорит пустой стек или нет */
    template <class Type_stack, class Container_stack>
    bool stack<Type_stack, Container_stack>::empty() const
    {
        return _container.empty();
    }
    
    /* Кол во элементов в стеке */
    template <class Type_stack, class Container_stack>
	typename stack<Type_stack, Container_stack>::size_type stack<Type_stack, Container_stack>::size() const
    {
        return _container.size();
    }

    /* Return top element in stack*/
    template <class Type_stack, class Container_stack>
	typename stack<Type_stack, Container_stack>::reference stack<Type_stack, Container_stack>::top()
    {
        return _container.back();
    }
    
    /* Return top element in stack*/
    template <class Type_stack, class Container_stack>
	typename stack<Type_stack, Container_stack>::const_reference stack<Type_stack, Container_stack>::top() const
    {
        return _container.back();
    }

    /* Вставляет элемент в верхушку стека*/
    template <class Type_stack, class Container_stack>
    void stack<Type_stack, Container_stack>::push(const value_type& value)
    {
        _container.push_back(value);
    }

    /* Удаляет элемент поверх стека вызывая его деструктор*/
    template <class Type_stack, class Container_stack>
    void stack<Type_stack, Container_stack>::pop()
    {
        _container.pop_back();
    }
    
    /* Обменивает содержимое адаптера контейнера (*this) на содержимое x. */
    template <class Type_stack, class Container_stack>
    void stack<Type_stack, Container_stack>::swap(stack & other_stack)
    {
        ft::swap(_container, other_stack._container);
    }
}

#endif