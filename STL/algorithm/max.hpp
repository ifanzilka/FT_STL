/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:11:01 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:11:02 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAX
# define FT_MAX

namespace ft
{
	template<class T> inline
	const T& max(const T& X, const T& Y)
	{
		return (X < Y ? Y : X);
	}

	template<class T, class Pr> inline
	const T& max(const T& X, const T& Y, Pr P)
	{
		return (P(X, Y) ? Y : X);
	}
}

#endif
