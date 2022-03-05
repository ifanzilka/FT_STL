#ifndef FT_XTREE_FUNCTION
# define FT_XTREE_FUNCTION

#include "xtree.hpp"

namespace ft
{   

    /* Tr-> Tree_traits */
    
    /* Кол-во элементов в дереве*/
    template <class Tr>
    typename Tree<Tr>::size_type Tree<Tr>::size() const
    {
        return (Size);
    }

    /* Максимальное кол-во памяти в аллокаторе*/
    template <class Tr>
    typename Tree<Tr>::size_type Tree<Tr>::max_size() const
    {
        return (Tree::Alval.max_size());
    }

    /* True если пустой */
    template <class Tr>
    bool Tree<Tr>::empty() const
    {
        return (size() == 0);
    }

    template <class Tr>
    typename Tree<Tr>::key_compare Tree<Tr>::key_comp() const
    {
        return (Tr::comp);
    }

    template <class Tr>
    typename Tree<Tr>::value_compare Tree<Tr>::value_comp() const
    {
        return (value_compare(key_comp()));
    }
}

#endif