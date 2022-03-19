/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:14:12 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/19 17:39:12 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PAIR
# define FT_PAIR


/*
** Пара значений
** Этот класс объединяет пару значений, которые могут быть разных типов (T1 и T2).
** Доступ к отдельным значениям можно получить через его общедоступных участников первого и второго.
*/

namespace ft
{
    template <class T, class U>
    struct pair
    {
        typedef T first_type;
        typedef U second_type;
        
        T first;
        U second;
        
        /* Constructors */
        pair(): first(), second() {}

        /* Constructors */
        pair(const T& x, const U& y):first(x), second(y)
        {

        }
        
        /* Constructors */
        template<class V, class W>
        pair(const pair<V, W>& pr): first(pr.first), second(pr.second)
        {

        }

        void swap(pair<T, U>& pr )
        {
            pair <T, U> tmp(pr.first, pr.second);

            pr.first = this->first ;
            pr.second = this->second ;
            this->first = tmp.first;
            this->second = tmp.second;
        }

    };
		
	template <class T, class U>
	pair<T, U> make_pair(T x, U y)
	{
		return pair<T, U>(x, y);
	}
    
	template <class T, class U>
	inline bool  operator == (const pair<T, U>& x, const pair<T, U>& y)
    {
	    return x.first == y.first && x.second == y.second ;
	}

	template <class T, class U>
	inline bool operator != (const pair<T, U>& x, const pair<T, U>& y)
    {
	    return !(x == y);
	}

	template <class T, class U>
	inline bool operator < (const pair<T, U>& x, const pair<T, U>& y)
    {
	    return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
	}

	template <class T, class U>
	inline bool operator > (const pair<T, U>& x, const pair<T, U>& y)
    {
	    return y < x;
	}

	template <class T, class U>
	inline bool operator <= (const pair<T, U>& x, const pair<T, U>& y)
    {
	    return !(y < x);
	}

	template <class T, class U>
	inline bool operator >= (const pair<T, U>& x, const pair<T, U>& y)
    {
	    return !(x < y);
	}

};
#endif