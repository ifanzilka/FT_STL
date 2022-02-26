#ifndef FT_STACK_CONSTRUCTOR
# define FT_STACK_CONSTRUCTOR

# include "stack.hpp"

namespace ft
{
    /* Конструктор */
    template <class Type_stack, class Container_stack>
    stack<Type_stack, Container_stack>::stack(): _container(container_type())
    {

    }
    
    /* Конструктор с контейнером */
    template <class Type_stack, class Container_stack>
	stack<Type_stack, Container_stack>::stack(const container_type & Cont): _container(Cont)
    {

    }


    /* Переопределние оператора = */
    template <class Type_stack, class Container_stack>
	stack<Type_stack, Container_stack>& stack<Type_stack, Container_stack>::operator = (const stack& copy)
    {
        _container = copy._container;
        return *this;
    }

    /* Констсруктор копирования  */
    template <class Type_stack, class Container_stack>
	stack<Type_stack, Container_stack>::stack(const stack& copy): _container(copy._container)
    {

    }

    /* Деструктор */
	template <class Type_stack, class Container_stack>
    stack<Type_stack, Container_stack>::~stack()
    {
        
    }
}


#endif