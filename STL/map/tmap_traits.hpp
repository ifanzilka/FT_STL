/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmap_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:13:18 by bmarilli          #+#    #+#             */
/*   Updated: 2022/04/03 19:41:37 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TMAP_TRAITS
# define FT_TMAP_TRAITS

/* Pair */
#include "../utility/utility.hpp"

/* binary function */
#include "../functional/functional.hpp"

namespace ft
{
    /*****************************************************/
    /*                  TMAP_TRAITS                       */
    /*****************************************************/

    template <class K, class T, class Pr, class Ax, bool Mfl>
	class Tmap_traits
	{
	public:
		typedef K						key_type;
		/* Что хранится в ноде */
		typedef ft::pair<const K, T>	value_type;
		typedef Pr						key_compare;
		typedef typename Ax::template rebind<value_type>::other
				allocator_type;

		enum
		{
			Multi = Mfl
		};

		Tmap_traits(): comp()
		{

		}

		Tmap_traits(Pr Parg): comp(Parg)
		{

		}

		class value_compare: public ft::binary_function<value_type, value_type, bool>
		{

			friend class Tmap_traits<K, T, Pr, Ax, Mfl>;
			public:
				
				bool operator()(const value_type &X, const value_type &Y) const
				{
					return(comp(X.first, Y.first));
				}

				value_compare(key_compare Pred): comp(Pred)
				{

				}

			protected:
					/* Класс  сравнения */
					key_compare comp;
		};

		/* Получаем ключ */
		const static K &GetKey(const value_type &V)
		{
			return (V.first);
		}

		Pr comp;
	};
}

#endif