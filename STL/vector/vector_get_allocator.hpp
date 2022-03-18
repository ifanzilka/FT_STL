/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get_allocator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:14:33 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:14:33 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_ALLOC
# define FT_GET_ALLOC

#include "vector.hpp"

namespace ft
{
    template<class T, class Alloc>
    typename vector<T,Alloc>::allocator_type vector<T,Alloc>::get_allocator() const
    {
        return (_base::Alval);
    }
}

#endif