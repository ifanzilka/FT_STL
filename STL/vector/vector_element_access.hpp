#ifndef FT_VECTOR_ELEMENT_ACCESS
# define FT_VECTOR_ELEMENT_ACCESS

# include "vector.hpp"
# include "vector_iterators.hpp"

namespace ft
{
    /* Пеоеопределение операторов */
    template <class T, class Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type N) const
    {
        /* К итератору прибавили N  и разыменовали */
        return (*(begin() + N));
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type N)
    {
        /* К итератору прибавили N  и разыменовали */
        return (*(begin() + N));
    }

    /* N element , отличие от [] тем что проверяется диапозон и выкидыаетя исключение out_of_range */
    template <class T, class Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type N) const
    {
        if (size() <= N)
            throw std::length_error("vector<T> too long");
            //throw RED"vector<T> subscript"F_NONE;
		return (*(begin() + N));
    }

    /* N element , отличие от [] тем что проверяется диапозон и выкидыаетя исключение out_of_range */
    template <class T, class Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type N)
    {
        if (size() <= N)
			throw std::length_error("vector<T> subscript");
            //throw RED"vector<T> subscript"F_NONE;
		return (*(begin() + N));	
    }

    /* Возращает первый эдлемент */
    template <class T, class Alloc>
    typename vector<T, Alloc>::reference  vector<T, Alloc>::front()
    {
        /* Создали итератор и разыменовали */
		return(*begin());
    }

    /* Возращает первый эдлемент */
    template <class T, class Alloc>
    typename vector<T, Alloc>::const_reference  vector<T, Alloc>::front() const
    {
        /* Создали итератор и разыменовали */
		return(*begin());
    }

    /* Возвращает последний элемент */
    template <class T, class Alloc>
    typename vector<T, Alloc>::reference  vector<T, Alloc>::back()
    {
        return(*(end() - 1));
    }

    /* Возвращает последний элемент */
    template <class T, class Alloc>
    typename vector<T, Alloc>::const_reference  vector<T, Alloc>::back() const
    {
        return(*(end() - 1));
    }
}

#endif