#ifndef FT_VECTOR_CONSTRUCTOR
# define FT_VECTOR_CONSTRUCTOR

#include "vector_header.hpp"
#include "vector_protected.hpp"

namespace ft
{
        /* Constructor */
    template<class T,  class Alloc>
	vector<T, Alloc>::vector(): _base()
    {
        Allocate_zero(0);
    }
    
    /* Конструктор с аллокатором */
    template<class T,  class Alloc>
    vector<T, Alloc>::vector (const allocator_type& Al): _base(Al)
    {
        Allocate_zero(0);
    }
    
    /* Конструктор с размером  */
    template<class T,  class Alloc>
    vector<T, Alloc>::vector (size_type N) : _base()
    {
        if (Allocate_zero(N))
            Last = Call_construct(First, N, T());
    }
    
    /* Констурктор размер и тип */
    template<class T,  class Alloc>
    vector<T, Alloc>::vector (size_type N, const T& V): _base()
    {
        if (Allocate_zero(N))
            Last = Call_construct(First, N, V);
    }
    
    /* Конструктор размер тип и аллокатор*/
    template<class T,  class Alloc>
    vector<T, Alloc>::vector(size_type N, const T& V, const allocator_type& Al) : _base(Al)
    {
        if (Allocate_zero(N))
            Last = Call_construct(First, N, V);
    }
    
    /*Констркутор с вектором */
    template<class T,  class Alloc>
    vector<T, Alloc>::vector(const vector& X): _base(X.Alval)
    {
         if (Allocate_zero(X.size()))
            Last = ItCopy(X.begin(), X.end(), First);
    }

    /* Конструкторы с итераторами */
    template<class T,  class Alloc>
    template<class It>
    vector<T, Alloc>::vector(It First, It Last): _base()
    {
        Construct(First, Last, ft::Iter_cat(First));
    }
    
    /* Конструкторы с итераторами  и аллокатором */
    template<class T,  class Alloc>
    template<class It>
    vector<T, Alloc>::vector (It First, It Last, const allocator_type& Al) : _base(Al)
    {
        Construct(First, Last, ft::Iter_cat(First));
    }

    /* Деструктор */
    template<class T,  class Alloc>
    vector<T, Alloc>::~vector()
    {
        Clear();
    }
}

#endif