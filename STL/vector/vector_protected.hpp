#ifndef FT_VECTOR_PROTECTED
# define FT_VECTOR_PROTECTED

#include "vector_header.hpp"

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
    vector<T, Alloc>::pointer vector<T, Alloc>::Call_construct(pointer Q, size_type N, const T& X)
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
    vector<T, Alloc>::pointer vector<T, Alloc>::ItCopy(It First, It Last, pointer Ptr)
    {
        pointer CopyPtr = Ptr;

        try
        {
            for(; First != Last; ++Ptr, ++First)
                _base::Alval.construct(Ptr, *First); // *Firts -> значение
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
        //insert(begin(), F, L);
    }

}

#endif