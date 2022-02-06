#ifndef FT_ITER_CAT
# define FT_ITER_CAT

# include "iterator.hpp"

/* 
** Эти функции нужны для понимаю какой из классов
** шаблонной функции пришел
** раньще называлась std::__iterator_category
*/

namespace ft
{
	template<class C, class T, class Dist> inline
	C Iter_cat (const ft::iterator<C, T, Dist> &)
	{
		C x;
		return (x);
	}

	template <class T> inline
	ft::random_access_iterator_tag Iter_cat(const T*)
	{
		ft::random_access_iterator_tag x;
		return (x);
	}
};

#endif