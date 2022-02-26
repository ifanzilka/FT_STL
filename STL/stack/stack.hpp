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

		/* C++ 11 */
		typedef Container_stack								container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;
		typedef typename container_type::size_type			size_type;

		/*****************************************************/
		/*                      Constructors                 */
		/*****************************************************/


		/* Конструктор без параметров (берем шаблонный контейнер) */
		stack();
		//stack(): _container(container_type&& ctnr =  container_type());


		/* Конструктор с контейнером */
		explicit stack(const container_type & Cont);

	
		// template <class Alloc>
		// explicit stack (const Alloc& alloc);
		
		// template <class Alloc>
		// stack (const container_type& ctnr, const Alloc& alloc);
		
		// template <class Alloc>
		// stack (container_type&& ctnr, const Alloc& alloc);

		// template <class Alloc>
		// stack (const stack& x, const Alloc& alloc);

		// template <class Alloc>
		// stack (stack&& x, const Alloc& alloc);

		/* Деструктор */
		~stack();

		/* Переопределние оператора = */
		stack& operator = (const stack& copy);

		/* Констсруктор копирования  */
		stack(const stack& copy);


		/*****************************************************/
        /*                MEMBER FUNCTION                   */
        /*****************************************************/

		/* Говорит пустой стек или нет */
		bool empty() const;

		/* Кол во элементов в стеке */
		size_type size() const;

		/* Return top element in stack*/
		reference top();
		
		/* Return top element in stack*/
		const_reference top() const;

		/* Вставляет элемент в верхушку стека*/
		void push(const value_type& value);

		/* Удаляет элемент поверх стека вызывая его деструктор*/
		void pop();

		/* Обменивает содержимое адаптера контейнера (*this) на содержимое x. */
		void swap(stack & x);

	protected:
		container_type _container;

	};

	/* Определяем операторы */
    template <class Type, class Container>
	bool operator == (const stack<Type, Container> & x, const stack<Type, Container> & y)
	{
	    return (x._container == y._container);
	};

	template <class Type, class Container>
	bool operator != (const stack<Type, Container> & x, const stack<Type, Container> & y)
	{
		return (!(x == y));
	};

	template <class Type, class Container>
    bool operator < (const stack<Type, Container> & x, const stack<Type, Container> & y)
    {
        return (x.c < y.c);
    };

	template <class Type, class Container>
    bool operator > (const stack<Type, Container> & x, const stack<Type, Container> & y)
    {
        return (y < x);
    };

	template <class Type, class Container>
    bool operator >= (const stack<Type, Container> & x, const stack<Type, Container> & y)
    {
        return (!(x < y));
    };

	template <class Type, class Container>
    bool operator <= (const stack<Type, Container> & x, const stack<Type, Container> & y)
    {
        return (!(y < x));
    };
}


#include "stack_constructor.hpp"
#include "stack_function.hpp"

#endif