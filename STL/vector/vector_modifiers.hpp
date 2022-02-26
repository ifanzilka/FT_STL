#ifndef FT_VECTOR_MODIFIERS
# define FT_VECTOR_MODIFIERS

#include "vector.hpp"
// #include "vector_protected.hpp"
// #include "vector_iterators.hpp"

namespace ft
{
    /* Присваивает вектору новое содержимое, заменяя его текущее содержимое и соответствующим образом изменяя его размер. */
    template <class T, class Alloc>
    template <class It>
    void vector<T, Alloc>::assign(It F, It L)
    {
        Assign(F, L, ft::Iter_cat(F));
    }

    /* Присваивает вектору новое содержимое,  N раз элемент X */
    template <class T, class Alloc>
    void vector<T, Alloc>::assign(size_type N, const T& X)
    {
        T Tx = X;
		
        erase(begin(), end());
		insert(begin(), N, Tx);
    }

    /* Добавить элемент в конeц */
    template <class T, class Alloc>
    void vector<T, Alloc>::push_back(const T& X)
    {
        insert(end(), X);
    }

    /* Удалить последний элемент */
    template <class T, class Alloc>
    void vector<T, Alloc>::pop_back()
    {   
        /* Стираем один элемент */
        erase(end() -1);
    }

    /* Вставление элемента X перед итератором P (возвращаю итератор на вставленный элемент) */
    template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator P, const T& X)
    {
        size_type Off;
        if (size() == 0)
            Off = 0;
        else
            Off = P - begin();
        insert(P, (size_type)1, X);
        return (begin() + Off);
    }
    
    /* Вставление элемента X перед итератором P  (M раз) (возвращаю итератор на вставленный элемент) */
    template <class T, class Alloc>
    void vector<T, Alloc>::insert(iterator P, size_type M, const T& X)
    {
        T Tx = X;
        size_type N = capacity();
        
        if (M == 0)
            ;
        else if (max_size() - size() < M)
        {
            throw RED"vector<T> too long"F_NONE;
        }
        else if (N < size() + M)
        {
            /* Если не хватает места под новые M элементов*/
            if ((max_size() - N / 2) < N)
                N = 0;
            else
                N = N + N / 2;
            if (N < size() + M)
                N = size() + M;

            pointer S = _base::Alval.allocate(N, (void *) 0);
            pointer Q;
            try
            {
                Q = ItCopy(begin(), P, S);
                /* Вставляю новые элементы */
                Q = Call_construct(Q, M, Tx);
                /* Копирую остальную часть */
                ItCopy(P, end(), Q);
            }
            catch (...)
            {
                Destroy(S, Q);
                _base::Alval.deallocate(S, N);
                throw ;
            }
            if (First != 0)
            {
                /* Вызываю деструторы */
                Destroy(First, Last);
                /* Очищаю */
                _base::Alval.deallocate(First, End - First);
            }
            End = S + N;
            Last = S + size() + M;
            First = S;
        }
        else if ((size_type)(end() - P) < M)
        {
            /* Если нужно увеличить размер вектора (не переаллацируя!!! (то есть памяти хватает)) */
            
            /* Последние элементы смещаю назад*/
            ItCopy(P, end(), P.base() + M);
            try
            {
                Call_construct(Last, M - (end() - P), Tx);
            }
            catch (...)
            {
                Destroy(P.base() + M, Last + M);
                throw;
            }
            Last += M;
            ft::fill(P, end() - M, Tx);
        }
        else
        {
            iterator Oend = end();
            Last = ItCopy(Oend - M, Oend, Last);
            ft::copy_backward(P, Oend - M, Oend);
            ft::fill(P, P + M, Tx);
        }   
    }

    /* Вставление элементов в позицию P, от F до L */
    template <class T, class Alloc>
    template <class It>
	void vector<T, Alloc>::insert(iterator Position, It First, It Last)
    {
        Insert(Position, First, Last, Iter_cat(First));
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

    /* Стирание элемента в промежутке Вызывая леструктор */
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
            ft::swap(First, X.First);
            ft::swap(Last, X.Last);
            ft::swap(End, X.End);
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