/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_distance.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <ifanzilka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:12:39 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/21 00:02:03 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITER_DISTANCE
#define FT_ITER_DISTANCE

#include "iterator.hpp"

namespace ft
{
	/* Template function Distance */

	template <class InIt> inline
	typename ft::iterator_traits<InIt>::difference_type distance(InIt F, InIt L)
	{
		typename ft::iterator_traits<InIt>::difference_type N = 0;
		Distance2(F, L, N, ft::Iter_cat(F));
		return (N);
	}

	template <class InIt, class D> inline
	void Distance(InIt F, InIt L, D & N)
	{
		Distance2(F, L, N, ft::Iter_cat(F));
	}

	template <class InIt, class D> inline
	void Distance2(InIt F, InIt L, D & N, input_iterator_tag)
	{
		for (; F != L; ++F)
		{
			++N;
		}
	}

	template <class InIt, class D> inline
	void Distance2(InIt F, InIt L, D & N, forward_iterator_tag)
	{
		for (; F != L; ++F)
		{
			++N;
		}
	}

	template <class InIt, class D> inline
	void Distance2(InIt F, InIt L, D & N, bidirectional_iterator_tag)
	{
		for (; F != L; ++F)
		{
			++N;
		}
	}

	template <class InIt, class D> inline
	void Distance2(InIt F, InIt L, D & N, ft::random_access_iterator_tag)
	{
		N += L - F;
	}


	/*********FROM TREE ******/

	template <class InIt, class D> inline
	void Distance_Tree(InIt F, InIt L, D & N)
	{
		for (; F != L; ++F)
		{
			++N;
		}
	}
	
}

#endif