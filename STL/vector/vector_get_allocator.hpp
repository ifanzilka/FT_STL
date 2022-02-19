#ifndef FT_GET_ALLOC
# define FT_GET_ALLOC

#include "vector_header.hpp"

namespace ft
{
    template<class T, class Alloc>
    vector<T,Alloc>::allocator_type vector<T,Alloc>::get_allocator() const
    {
        return (_base::Alval);
    }
}

#endif