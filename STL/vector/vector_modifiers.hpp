#ifndef FT_VECTOR_MODIFIERS
# define FT_VECTOR_MODIFIERS

#include "vector_header.hpp"

namespace ft
{
    /* Присваивает вектору новое содержимое, заменяя его текущее содержимое и соответствующим образом изменяя его размер. */
    template <class T, class Alloc>
    template <class It>
    void vector<T, Alloc>::assign(It F, It L)
    {

    }

    template <class T, class Alloc>
    void vector<T, Alloc>::assign(size_type N, const T& X)
    {

    }

    /* Добавить элемент в конeц */
    template <class T, class Alloc>
    void vector<T, Alloc>::push_back(const T& X)
    {

    }

    /* Удалить последний элемент */
    template <class T, class Alloc>
    void vector<T, Alloc>::pop_back()
    {

    }

    /* Вставление элемента X перед итератором P (возвращаю итератор на вставленный элемент) */
    template <class T, class Alloc>
	vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator P, const T& X)
    {
        return (0);
    }
    
    /* Вставление элемента X перед итератором P  (M раз) (возвращаю итератор на вставленный элемент) */
    template <class T, class Alloc>
    void vector<T, Alloc>::insert(iterator P, size_type M, const T& X)
    {

    }

    template <class T, class Alloc>
    template <class It>
	void vector<T, Alloc>::insert (iterator P, It F, It L)
    {

    }

    /* Стирание элемента P по итератору или в промежутке */
    template <class T, class Alloc>
	vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator P)
    {

    }

    /* Стирание элемента P по итератору или в промежутке */
    template <class T, class Alloc>
    vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator F, iterator L)
    {

    }

    /* Поменять местами содержимое */
    template <class T, class Alloc>
    void vector<T, Alloc>::swap(vector &X)
    {

    }

    /* Очищаем */
    template <class T, class Alloc>
    void vector<T, Alloc>::clear()
    {

    }
}

#endif