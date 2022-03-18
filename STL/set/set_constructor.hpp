/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_constructor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:13:37 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:13:37 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_CONSTRUCTOR
# define FT_SET_CONSTRUCTOR

#include "set.hpp"
#include "../xtree/xtree.hpp"

namespace ft
{
    template<class K, class Pr, class A >
    set<K, Pr, A>::set(): Mybase(key_compare(), allocator_type())
    {
    
    }

    template<class K, class Pr, class A >
    set<K, Pr, A>::set(const key_compare &Pred): Mybase(Pred, allocator_type())
    {

    }

    template<class K, class Pr, class A >
    set<K, Pr, A>::set(const key_compare &Pred, const set<K, Pr, A>::allocator_type &Al): Mybase(Pred, Al)
    {

    }

    template<class K, class Pr, class A >
    template<class It>
    set<K, Pr, A>::set(It F, It L): Mybase(key_compare(), allocator_type())
    {
        for (; F != L; ++F)
        {
            Tree< Tset_traits<K, Pr, A, false > >::insert(*F);
        }
    }

    template<class K, class Pr, class A >
    template<class It>
    set<K, Pr, A>::set(It F, It L, const key_compare &Pred): Mybase(Pred, allocator_type())
    {
        for (; F != L; ++F)
        {
            Tree< Tset_traits<K, Pr, A, false > >::insert(*F);
        }
    }

    template<class K, class Pr, class A >
    template<class It>
    set<K, Pr, A>::set(It F, It L, const key_compare &Pred, const allocator_type &Al): Mybase(Pred, Al)
    {
        for (; F != L; ++F)
        {
            Tree< Tset_traits<K, Pr, A, false > >::insert(*F);
        }
    }

}

#endif