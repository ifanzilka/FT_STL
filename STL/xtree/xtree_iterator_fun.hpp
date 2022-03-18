/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtree_iterator_fun.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:15:28 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:15:29 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XTREE_ITERATOR_FUN
# define FT_XTREE_ITERATOR_FUN

#include "xtree.hpp"

namespace ft
{
    /* Tr-> Tree_traits */
    
    /* Возвращает двухнаправленный итератор на начало или след элемент после end() */
    template <class Tr>
    typename Tree<Tr>::iterator  Tree<Tr>::begin()
    {
        return (iterator(Lmost()));
    }

    /* Возвращает двухнаправленный итератор на начало или след элемент после end() */
    template <class Tr>
    typename Tree<Tr>::const_iterator  Tree<Tr>::begin() const
    {
        return (const_iterator(Lmost()));
    }

    template <class Tr>
    typename Tree<Tr>::iterator  Tree<Tr>::end()
    {
        return (iterator(Head));
    }

    template <class Tr>
    typename Tree<Tr>::const_iterator  Tree<Tr>::end() const
    {
        return (const_iterator(Head));
    }

    template <class Tr>
    typename Tree<Tr>::reverse_iterator  Tree<Tr>::rbegin()
    {
        return (reverse_iterator(end()));
    }

    template <class Tr>
    typename Tree<Tr>::const_reverse_iterator  Tree<Tr>::rbegin() const
    {
        return  (const_reverse_iterator(end()));
    }

    template <class Tr>
    typename Tree<Tr>::reverse_iterator  Tree<Tr>::rend()
    {
        return (reverse_iterator(begin()));
    }

    template <class Tr>
    typename Tree<Tr>::const_reverse_iterator  Tree<Tr>::rend() const
    {
        return (const_reverse_iterator(begin()));
    }

}

#endif