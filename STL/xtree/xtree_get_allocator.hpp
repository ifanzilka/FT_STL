/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtree_get_allocator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:15:23 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 19:25:04 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XTREE_GET_ALLOCATOR
# define FT_XTREE_GET_ALLOCATOR

#include "xtree.hpp"

namespace ft
{
    template <class Tree_traits>
    typename Tree<Tree_traits>::allocator_type Tree<Tree_traits>::get_allocator() const
    {
        //return (Alval);
        return (Mybase::Alval);
    }
}

#endif