/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mismatch.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:11:15 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/19 01:38:17 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MISMATCH
# define FT_MISMATCH

# include "algorithm.hpp"

/* PAIR */
# include "../utility/pair.hpp"

namespace ft
{

	/*
	** Сравнивает элементы в диапазоне [F,L) с элементами в диапазоне, начинающемся с X,
	** и возвращает первый элемент обеих последовательностей, который не совпадает.
	** Элементы сравниваются с помощью оператора== (или pred, в версии (2)).
	** Функция возвращает пару итераторов к первому элементу в каждом диапазоне, который не совпадает.
	*/

	template <class InIt1, class InIt2> inline
	ft::pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X)
	{
		for (; F != L && *F == *X; ++F, ++X)
			;
		return (ft::pair<InIt1, InIt2>(F, X));
	}
	
	template <class InIt1, class InIt2, class Pr> inline
	ft::pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X, Pr P)
	{
		for (; F != L && P(*F, *X); ++F, ++X)
			;
		return (ft::pair<InIt1, InIt2>(F, X));
	}

};

#endif
