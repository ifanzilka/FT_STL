#ifndef FT_FILL
# define FT_FILL

namespace ft
{
	/*
	** Заполните диапазон значением
	** Присваивает значение X всем элементам в диапазоне [F,l).
	*/

	template <class FwdIt, class T> inline
	void fill(FwdIt F, 	FwdIt L,  const T & X)
	{

		for (; F != L ; ++F)
			*F = X;
	}

	template <class OutIt, class Sz, class T> inline
	void fill_n(OutIt F, Sz N,  const T & X)
	{

		for (; 0 < N ; --N, ++F)
			*F = X;
	}



};

#endif 