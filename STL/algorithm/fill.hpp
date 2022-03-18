/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:10:44 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:10:45 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILL
# define FT_FILL

namespace ft
{
	/*
	** Заполните диапазон значением
	** Присваивает значение X всем элементам в диапазоне [First, Last).
	*/

	template <class FwdIt, class T> inline
	void fill(FwdIt First, 	FwdIt Last,  const T & X)
	{

		for (; First != Last ; ++First)
			*First = X;
	}

	/* Заполняем n раз */
	template <class OutIt, class Sz, class T> inline
	void fill_n(OutIt First, Sz N,  const T & X)
	{

		for (; 0 < N ; --N, ++First)
			*First = X;
	}



};

#endif 
