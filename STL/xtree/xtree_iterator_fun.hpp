#ifndef FT_XTREE_ITERATOR_FUN
# define FT_XTREE_ITERATOR_FUN

#include "xtree.hpp"

namespace ft
{
    /* Tr-> Tree_traits */
    
    template <class Tr>
    typename Tree<Tr>::iterator  Tree<Tr>::begin()
    {
        return (iterator(Lmost()));
    }


    template <class Tr>
    typename Tree<Tr>::const_iterator  Tree<Tr>::begin() const
    {
        return (const_iterator(Lmost()));
    }

    template <class Tr>
    typename Tree<Tr>::iterator  Tree<Tr>::end()
    {
        return (iterator(Head));
    }

    template <class Tr>
    typename Tree<Tr>::const_iterator  Tree<Tr>::end() const
    {
        return (const_iterator(Head));
    }

    template <class Tr>
    typename Tree<Tr>::reverse_iterator  Tree<Tr>::rbegin()
    {
        //
    }

    template <class Tr>
    typename Tree<Tr>::const_reverse_iterator  Tree<Tr>::rbegin() const
    {
        //
    }

    template <class Tr>
    typename Tree<Tr>::reverse_iterator  Tree<Tr>::rend()
    {
        //
    }

    template <class Tr>
    typename Tree<Tr>::const_reverse_iterator  Tree<Tr>::rend() const
    {
        //
    }

}

#endif