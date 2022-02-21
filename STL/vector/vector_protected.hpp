#ifndef FT_VECTOR_PROTECTED
# define FT_VECTOR_PROTECTED

#include "vector_header.hpp"
#include "vector_modifiers.hpp"

namespace ft
{
    /* Выделяем память и заполянем нулями и инициализируем указатели*/
    template<class T,  class Alloc>
    bool vector<T, Alloc>::Allocate_zero(size_type N)
    {
        First = 0, Last = 0, End = 0;
        if (N == 0)
            return (false);
        else
        {
            First = _base::Alval.allocate(N, (void *)0);
            Last = First;
            End = First + N;
            return (true);
        }
    }

    /* Вызываю  N раз конструктор в области памяти Q и возвращаю указатель где вызывали Ufill */
    template<class T,  class Alloc>
    typename vector<T, Alloc>::pointer vector<T, Alloc>::Call_construct(pointer Q, size_type N, const T& X)
    {
        pointer Qs = Q;
        try
        {
            for(; 0 < N; --N, ++Q)
                _base::Alval.construct(Q, X);
        }
        catch (...)
        {
            Destroy(Qs, Q);
            throw;
        }
        return (Q);
    }

    /* Копируем зачения от First до Last (Ucopy) */
    template<class T,  class Alloc>
    template<class It>
    typename vector<T, Alloc>::pointer vector<T, Alloc>::ItCopy(It First, It Last, pointer Ptr)
    {
        pointer CopyPtr = Ptr;

        try
        {
            for(; First != Last; ++Ptr, ++First)
            {
                _base::Alval.construct(Ptr, *First); // *Firts -> значение
            }
        }
        catch (...)
        {
            Destroy(CopyPtr, Ptr);
            throw;
        }
        return (Ptr);
    }

    /* Вызываем деструкторы  */
    template<class T,  class Alloc>
    void  vector<T, Alloc>::Destroy(pointer F, pointer L)
    {
        for(; F != L; ++F)
            _base::Alval.destroy(F);
    }

    /* Вызываю деструкторы и очищаю память */
    template<class T,  class Alloc>
    void vector<T, Alloc>::Clear()
    {
        if (First != 0)
        {
            Destroy(First, Last);
            /* Очищаем область */
            _base::Alval.deallocate(First, End - First);
        }
        First = 0, Last = 0, End = 0;
    }

    template<class T,  class Alloc>
    template <class It>
    void vector<T, Alloc>::Construct(It F, It L, Int_iterator_tag)
    {
        size_type N = (size_type)F;
        if (Allocate_zero(N))
            Last = Call_construct(First, N, (T)L);
    }

    template<class T,  class Alloc>
    template <class It>
    void vector<T, Alloc>::Construct(It F, It L, input_iterator_tag)
    {
        Allocate_zero(0);
        insert(begin(), F, L);
    }

    /* Вставление элементов из последовательности [F, L) */
    template<class T,  class Alloc>
    template <class It>
    void vector<T, Alloc>::Insert(iterator P, It F, It L, Int_iterator_tag)
    {

    }

    /* Вставление элементов из последовательности [F, L) */
    template<class T,  class Alloc>
    template <class It>
    void vector<T, Alloc>::Insert(iterator P, It F, It L, input_iterator_tag)
    {
        //std::cout<<"2\n";
    }

    /* Вставление элементов из последовательности [F, L) в  итератор P */
    template<class T,  class Alloc>
    template <class It>
    void vector<T, Alloc>::Insert(iterator P, It F, It L, forward_iterator_tag)
    {
        /* P -> begin() */
        size_type M = 0;

        /* Меняем М до (F - L) */
        ft::Distance(F, L, M);
        size_type N = capacity();
        
        if (M == 0)
            ;
        else if (max_size() - size() < M)
        {
            std::cout << "Error(Xlen)\n";
        }
        else if (N < size() + M) /* Если не хватает места под новые M элементов*/
        {
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
                Q = ItCopy(begin(), P, S); /* Вставляю новые элементы в новую аллоцированную память */
                Q = ItCopy(F, L, Q); /* Копирую остальную часть */
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
        else if ((size_type)(end() - P) < M) /* Если нужно увеличить размер вектора (не переаллацируя!!! (то есть памяти хватает)) */
        {            
            /* Последние элементы смещаю назад*/
            ItCopy(P, end(), P.base() + M);
            It Mid = F;
            advance(Mid, end() - P);

            try
            {
                ItCopy(Mid, L, Last);
            }
            catch (...)
            {
                Destroy(P.base() + M, Last + M);
                throw;
            }
            Last += M;
            copy(F, Mid, P);
        }
        else if (0 < M)
        {
            iterator Oend = end();
            Last = ItCopy(Oend - M, Oend, Last);
            ft::copy_backward(P, Oend - M, Oend);
            copy(F, L, P);
        }
    }
}

#endif