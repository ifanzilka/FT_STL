#ifndef FT_EQUAL
# define FT_EQUAL

namespace ft
{

	/*
	** Сравнивает элементы в диапазоне [F,L ) с элементами в диапазоне, начинающемся с X,
	** и возвращает значение true, если все элементы в обоих диапазонах совпадают.
	** Элементы сравниваются с помощью оператора== (или pred, в версии (2)).
	*/

	template <class InIt1, class InIt2> inline
	bool equal (InIt1 F, InIt1 L, InIt2 X)
	{
		return (ft::mismatch(F, L, X).first == L);
	}

	template <class InIt1, class InIt2, class Pr> inline
	bool equal (InIt1 F, InIt1 L, InIt2 X, Pr P)
	{
		return (ft::mismatch(F, L, X, P).first == L);
	}

}

#endif