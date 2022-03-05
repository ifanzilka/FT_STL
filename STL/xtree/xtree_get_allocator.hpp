#ifndef FT_XTREE_GET_ALLOCATOR
# define FT_XTREE_GET_ALLOCATOR

#include "xtree.hpp"

namespace ft
{
    template <class Tree_traits>
    typename Tree<Tree_traits>::allocator_type Tree<Tree_traits>::get_allocator() const
    {
        //return (Alval);
        return (Mybase::Alval);
    }
}

#endif