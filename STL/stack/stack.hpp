#ifndef FT_STACK
# define FT_STACK

# include "../vector/vector.hpp"

/* Page 590 */

namespace ft
{
    /* Наш стек основан на векторе */
    template <class Type_stack, class Container_stack = ft::vector<Type_stack> >
    class stack
    {
    public:
      typedef Container_stack								            container_type;
      typedef typename container_type::value_type			  value_type;
      typedef typename container_type::reference			  reference;
      typedef typename container_type::const_reference	const_reference;
      typedef typename container_type::size_type			  size_type;

        /* Конструктор с контейнером */
        explicit stack(const container_type & Cont): _container(Cont);

        /* Конструктор без параметров (берем шаблонный контейнер) */
        stack(): _container(container_type());

        /* Констсруктор копирования  */
        stack(const stack& copy) : _container(copy._container);


        /* Переопределние оператора = */
        stack& operator = (const stack& copy);


        bool empty() const;

        size_type size() const;

        reference top();

        const_reference top() const;

        void push(const value_type& value);

        void pop();

        void swap(stack & other_stack);
    
    protected:
		  container_type _container;

    };
}

#endif