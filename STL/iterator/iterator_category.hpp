#ifndef FT_ITERATOR_CATEGORY
# define FT_ITERATOR_CATEGORY

#include "iterator.hpp"

namespace ft
{
	/* T* -> указатель T& -> ссылка */
	template <class C, class T, class D = ptrdiff_t, class Pt = T*, class Rt = T&>  
	struct iterator
	{
		typedef C		iterator_category;
		typedef T		value_type;
		typedef D		difference_type;
		typedef Pt		pointer;
		typedef Rt		reference;
	};

    /* Наследуем свойства */
	template  <class T, class D, class Pt, class Rt>
	struct Bidit: public iterator<bidirectional_iterator_tag, T, D, Pt, Rt>
	{

	};

	/* Наследуем свойства*/
	template  <class T, class D, class Pt, class Rt>
	struct Ranit: public iterator<random_access_iterator_tag, T, D, Pt, Rt> 
	{

	};

    /* Наследуем свойства*/
    struct Outit: public iterator<output_iterator_tag, void ,void ,void ,void>
    {

    };

};

#endif