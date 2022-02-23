#ifndef FT_ITER_CAT
# define FT_ITER_CAT

# include "iterator.hpp"

/* 
** Эти функции нужны для понимания какой из классов
** шаблонной функции пришел
** раньще называлась std::__iterator_category
*/

namespace ft
{
	template<class C, class T, class Dist, class Pt, class Rt> inline
	C Iter_cat (const ft::iterator<C, T, Dist, Pt, Rt> &)
	{
		C x;
		return (x);
	}


	// template <class It> inline
	// typename iterator_traits<It>::iterator_category Iter_cat(It)
	// {
	// 	typename iterator_traits<It>::iterator_category x;

	// 	return (x);
	// }

	template <class T> inline
	ft::random_access_iterator_tag Iter_cat(const T*)
	{
		ft::random_access_iterator_tag x;
		return (x);
	}

	inline ft::Int_iterator_tag Iter_cat(bool)
	{
		Int_iterator_tag X;

		return (X);
	};

	inline ft::Int_iterator_tag Iter_cat(char)
	{
		Int_iterator_tag X;

		return (X);
	};

	inline ft::Int_iterator_tag Iter_cat(signed char)
	{
		Int_iterator_tag X;

		return (X);
	};

	inline ft::Int_iterator_tag Iter_cat(unsigned char)
	{
		Int_iterator_tag X;

		return (X);
	};

	inline ft::Int_iterator_tag Iter_cat(wchar_t)
	{
		Int_iterator_tag X;

		return (X);
	};

	inline ft::Int_iterator_tag Iter_cat(short)
	{
		Int_iterator_tag X;

		return (X);
	};

	inline ft::Int_iterator_tag Iter_cat(unsigned short)
	{
		Int_iterator_tag X;

		return (X);
	};

	inline ft::Int_iterator_tag Iter_cat(int)
	{
		Int_iterator_tag X;

		return (X);

	};

	inline ft::Int_iterator_tag Iter_cat(unsigned int)
	{
		Int_iterator_tag X;

		return (X);
	};

	inline ft::Int_iterator_tag Iter_cat(long)
	{
		Int_iterator_tag X;

		return (X);
	};

	inline ft::Int_iterator_tag Iter_cat(unsigned long)
	{
		Int_iterator_tag X;

		return (X);
	};

};

#endif