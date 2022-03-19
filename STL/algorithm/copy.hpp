/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:10:18 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/19 02:38:54 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COPY
# define FT_COPY

namespace ft
{
	/* Копируем в итератор X */
	template <class InIt, class OutIt> inline
	OutIt copy(InIt First, InIt Last, OutIt X)
	{
		for (; First != Last; ++X, ++First)
		{
			*X = *First;
		}
		return (X);
	}

	/* Копируем в итератор X */
	template <class BidIt1, class BidIt2> inline
	BidIt2 copy_backward(BidIt1 First, BidIt1 Last, BidIt2 X)
	{
		while (First != Last)
		{
			*--X = *--Last;
		}
		return (X);
	}

};

#endif
