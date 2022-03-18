/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_swap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:12:43 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:12:43 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITER_SWAP
# define FT_ITER_SWAP

namespace ft
{
	template <class FwdIt1, class FwdIt2, class T> inline
	void Iter_swap(FwdIt1 x, FwdIt2 y, T*)
	{
		T tmp = *x;
		*x = *y;
		*y = tmp;
	}
	
	/* меняем мсетами */
	template <class FwdIt1, class FwdIt2> inline
	void iter_swap(FwdIt1 x, FwdIt2 y)
	{
		Iter_swap(x, y, Val_type(x));
	}

}

#endif