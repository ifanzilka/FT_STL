#ifndef FT_VECTOR_ITERATORS
# define FT_VECTOR_ITERATORS

#include "vector.hpp"

namespace ft
{   
    /* Мы вызваем конуструктор итератора с указателем на первый элемент */
    template<class T, class Alloc>
    typename  vector<T, Alloc>::iterator vector<T, Alloc>::begin()
    {
        return (iterator(First));
    }

    /* Мы вызваем конуструктор итератора с указателем на первый элемент */
    template<class T, class Alloc>
    typename  vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
    {
        return (const_iterator(First));
    }

    /* Мы вызваем конуструктор итератора с указателем на последний элемент */
    template<class T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
    {
        return (iterator(Last));
    }

    /* Мы вызваем конуструктор итератора с указателем на последний элемент */
    template<class T, class Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
    {
        return (const_iterator(Last));
    }

    /* Мы вызваем конуструктор реверсивного  итератора c итератором на последнйи элемент */
    template<class T, class Alloc>
    typename vector<T, Alloc>::reverse_iterator  vector<T, Alloc>::rbegin()
    {
        return (reverse_iterator(end()));
    }

    /* Мы вызваем конуструктор реверсивного  итератора c итератором на последнйи элемент */
    template<class T, class Alloc>
    typename vector<T, Alloc>::const_reverse_iterator  vector<T, Alloc>::rbegin() const
    {
        return (const_reverse_iterator(end()));
    }

    /* Мы вызваем конуструктор реверсивного  итератора с итератором на первый элемент */
    template<class T, class Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
    {  
        return (reverse_iterator(begin()));
    }

    /* Мы вызваем конуструктор реверсивного  итератора с итератором на первый элемент */
    template<class T, class Alloc>
    typename vector<T, Alloc>::const_reverse_iterator  vector<T, Alloc>::rend() const
    {
        return (const_reverse_iterator(begin()));
    }
    
}

#endif