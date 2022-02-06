#ifndef FT_VAL_TYPE
# define FT_VAL_TYPE

# include "iterator.hpp"

namespace ft
{
	template <class It> inline
	typename ft::iterator_traits<It>::value_type *Val_type(It)
	{
		return (0);
	}


	/* Если компилятор не поддерживает частичную специализацию*/

	// template <class C, class T, class D, class Pt, class Rt> inline
	// T *Val_type(iterator, T, D, Pt, Rt)
	// {
	// 	return (0);	
	// }

	// template<class T> inline
	// T *Val_type(const T*)
	// {
	// 	return (0);
	// }

};

#endif