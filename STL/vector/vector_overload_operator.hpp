/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_overload_operator.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:14:48 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/19 12:53:26 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_OVERLOAD_OPERATOR
# define FT_VECTOR_OVERLOAD_OPERATOR

#include "vector.hpp"

namespace ft
{
    /* Переопределение оператора = */
    template <class T, class Alloc>
    vector<T, Alloc>& vector<T, Alloc>::operator=(const vector& X)
    {
        if (this == &X)
            ;
        else if (X.size() == 0)
        {
            Clear();
        }
        else if (X.size() <= size())
        {
            /* Если наш вектор больше чем тот откуда присваивание */

            pointer Q = ft::copy(X.begin(), X.end(), First);
            Destroy(Q, Last);
            Last = First + X.size();
        }
        else
        {
            /* Если размер нового вектора больше */
            Destroy(First, Last);
            
            _base::Alval.deallocate(First, End - First);
            
            if (Allocate_zero(X.size()))
            {
                Last = ItCopy(X.begin(), X.end(), First);
            }
        }
        return (*this);
    }
};

#endif
