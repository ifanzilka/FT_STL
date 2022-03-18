/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:14:21 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:14:22 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_CAPACITY
# define FT_VECTOR_CAPACITY

#include "vector.hpp"

namespace ft
{
    /* Возвращает размер вектора */
    template <class T, class Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>:: size() const
    {
        if (First == 0)
            return (0);
		return (Last - First);
    }

    /* Возвращет максимальный размер аллоцированной памяти */
    template <class T, class Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>:: max_size() const
    {
        return (_base::Alval.max_size());
    }

    /* Изменение размера контейнера чтобы он содержал n элементов !!!!*/
    template <class T, class Alloc>
    void vector<T, Alloc>::resize(size_type N, T X)
    {
        if (size() < N)
		    insert(end(), N - size(), X);
		else if (N < size())
			erase(begin() + N, end());
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::resize(size_type N)
    {
        resize(N, T());
    }

    /* Возвращаемый размер выделенной памяти */
    template <class T, class Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
    {
        if (First == 0)
			return (0);
		return (End - First);
    }

    /* Проверяет, является ли вектор пустым */
    template <class T, class Alloc>
    bool vector<T, Alloc>::empty() const
    {
        return (size() == 0);
    }

    /* Запросить изменение вместимости */
    template <class T, class Alloc>
    void vector<T, Alloc>::reserve(size_type N)
    {
        if (max_size() < N) 
            throw RED"vector<T> too long"F_NONE;
        else if (capacity() < N)
        {
            pointer Q = _base::Alval.allocate(N, (void *)0);

            try
            {
                ItCopy(begin(), end(), Q);
            }
            catch (...)
            {
                _base::Alval.deallocate(Q, N);
                throw ;
            }
            if (First != 0)
            {
                Destroy(First, Last);
                _base::Alval.deallocate(First, End - First);
            }
            End = Q + N;
            Last = Q + size();
            First = Q;
        }
    }

}   

#endif