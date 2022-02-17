#ifndef FT_lexicographical_compare
# define FT_lexicographical_compare

namespace ft
{
	/* 
	
	Лексикографическое сравнение меньше, чем сравнение
	Возвращает значение true, если диапазон [F,L) лексикографически меньше, чем диапазон [F2,L2).

	Лексикографическое сравнение - это вид сравнения, обычно используемый для сортировки слов в алфавитном порядке в словарях; Оно включает последовательное сравнение элементов, которые занимают одинаковое положение в обоих диапазонах, друг с другом до тех пор, пока один элемент не станет эквивалентным другому. Результатом сравнения этих первых несовпадающих элементов является результат лексикографического сравнения.

	Если обе последовательности сравниваются одинаково до тех пор, пока одна из них не закончится, то более короткая последовательность лексикографически меньше более длинной.

	Элементы сравниваются с помощью оператора< для первой версии и comp для второй. Два элемента a и b считаются эквивалентными, если (!(a<b) && !(b<a)) или если (!comp(a,b) && !comp(b,a)).

	*/

	template<class InIt1, class InIt2> inline
	bool lexicographical_compare(InIt1 F1, InIt1 L1, InIt2 F2, InIt2 L2)
	{
		for (; F1 != L1 && F2 != L2; ++F1, ++F2)
			if (*F1 < *F2)
				return (true);
			else if (*F2 < *F1)
				return (false);
		return (F1 == L1 && F2 != L2);
	}

	template<class InIt1, class InIt2, class Pr> inline
	bool lexicographical_compare(InIt1 F1, InIt1 L1, InIt2 F2, InIt2 L2, Pr P)
	{
		for (; F1 != L1 && F2 != L2; ++F1, ++F2)
			if (P(*F1, *F2))
				return (true);
			else if (P(*F2,*F1))
				return (false);
		return (F1 == L1 && F2 != L2);
	}

};

#endif