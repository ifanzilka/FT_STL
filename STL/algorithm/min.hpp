/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:11:09 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:11:10 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MIN
# define FT_MIN

namespace ft
{
	template<class T> inline
	const T& min(const T& X, const T& Y)
	{
		return (Y < X ? Y : X);
	}

	template<class T, class Pr> inline
	const T& min(const T& X, const T& Y, Pr P)
	{
		return (P(Y,X) ? Y : X);
	}
};

#endif
