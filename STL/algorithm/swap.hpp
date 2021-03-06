/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:11:24 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/19 12:51:14 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SWAP
# define FT_SWAP

namespace ft
{
	template <class T> inline
	void swap(T& X, T& Y)
	{
		T Tmp = X;
		X = Y;
		Y = Tmp;
	}
}

#endif
