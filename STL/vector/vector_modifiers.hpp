#ifndef FT_VECTOR_MODIFIERS
# define FT_VECTOR_MODIFIERS

#include "vector_header.hpp"
// #include "vector_protected.hpp"
// #include "vector_iterators.hpp"

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
        //T Tx = X;
		
        //erase(begin(), end());
		//insert(begin(), N, Tx);
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
	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator P, const T& X)
    {
        //return (0);
    }
    
    /* Вставление элемента X перед итератором P  (M раз) (возвращаю итератор на вставленный элемент) */
    template <class T, class Alloc>
    void vector<T, Alloc>::insert(iterator P, size_type M, const T& X)
    {

    }

    template <class T, class Alloc>
    template <class It>
	void vector<T, Alloc>::insert(iterator P, It F, It L)
    {
        Insert(P, F, L, Iter_cat(F));
    }

    /* Стирание элемента P по итератору */
    template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator P)
    {
        /* копируем элементы с позции P + 1 (грубо говоря смещаем на одну позцицию)*/
        ft::copy(P + 1, end(), P);
        Destroy(Last - 1, Last);
        --Last;
        return (P);
    }

    /* Стирание элемента в промежутке */
    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator F, iterator L)
    {
        if (F != L)
        {
            pointer S  = ft::copy(L, end(), F.base());
            Destroy(S, Last);
            Last = S;
        }
        return (F);
    }

    /* Поменять местами содержимое */
    template <class T, class Alloc>
    void vector<T, Alloc>::swap(vector &X)
    {
        /* Если совпали алокаторы*/
        if (_base::Alval == X.Alval)
        {
            // ДОДЕЛАТЬ!
            //ft::swap(First, X.First);
            //ft::swap(Last, X.Last);
            //ft::swap(End, X.End);
        }
        else
        {
            vector Tmp = *this;
            *this = X, X = Tmp;
        }
    }

    /* Очищаем */
    template <class T, class Alloc>
    void vector<T, Alloc>::clear()
    {
        erase(begin(), end());
    }
}

#endif