/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tset_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:13:45 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:13:46 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TSET_TRAITS
# define FT_TSET_TRAITS

namespace ft
{
    /* Traits позволяет не писаит длинный список параметров при инициалиазции Tree */
    template <class K, class Pr, class Al, bool Mfl>
	class Tset_traits
    {
    public:
        typedef K   key_type;
        typedef K   value_type;
        typedef Pr  key_compare;
        
        typedef typename Al::template rebind<value_type>::other allocator_type;

        enum
        {
            /* False если set/map */
            /* True если multiset/multimap */
            Multi = Mfl
        };

        Tset_traits(): comp(), v_comp() 
        {

        }
        
        Tset_traits(Pr Parg): comp (Parg), v_comp() 
        {

        }
        
        typedef key_compare value_compare;
        
        const static K &GetKey(const value_type &V)
		{
				//static key_type Key = (key_type)V;
				return (V);
		}

        struct Kfn
        {
            const K& operator() (const value_type & X ) const
            {
                return (X);
            }

            //Kfn k;
            //k()
            //key compare
            //key type
        };

        key_compare     comp;
        value_compare   v_comp;
	};
}

#endif