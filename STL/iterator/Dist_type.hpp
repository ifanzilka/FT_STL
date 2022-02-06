#ifndef FT_DIST_TYPE
# define FT_DIST_TYPE
# include "iterator.hpp"

namespace ft
{

	/* 
	**	Расстояние между двумя It 
	**  аналог iterator_traits::distance_type
	*/

	/* distance_type устаревшее имя*/

	
	// template<class It> inline
	// typename ft::iterator_traits::distance_type *Dist_type(It) // где есть частичная специализация
	// {
	// 	return (0);
	// }

	template<class C, class T, class D, class Pt, class Rt> inline
	D *Dist_type(iterator<C, T, D, Pt, Rt>)
	{
		return (0);
	}

	template <class T> inline
	ptrdiff_t *Dist_type(const T *)
	{
		return (0);
	}
	
};

#endif