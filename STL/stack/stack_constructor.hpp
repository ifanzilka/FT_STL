#ifndef FT_STACK_CONSTRUCTOR
# define FT_STACK_CONSTRUCTOR

# include "stack.hpp"

namespace ft
{
    /* Конструктор */
    template <class Type_stack, class Container_stack>
    stack<Type_stack, Container_stack>::stack(): c(container_type())
    {

    }
    
    /* Конструктор с контейнером */
    template <class Type_stack, class Container_stack>
	stack<Type_stack, Container_stack>::stack(const container_type & Cont): c(Cont)
    {

    }


    /* Переопределние оператора = */
    template <class Type_stack, class Container_stack>
	stack<Type_stack, Container_stack>& stack<Type_stack, Container_stack>::operator = (const stack& copy)
    {
        c = copy._container;
        return *this;
    }

    /* Констсруктор копирования  */
    template <class Type_stack, class Container_stack>
	stack<Type_stack, Container_stack>::stack(const stack& copy): c(copy.c)
    {

    }

    /* Деструктор */
	template <class Type_stack, class Container_stack>
    stack<Type_stack, Container_stack>::~stack()
    {
        
    }
}


#endif