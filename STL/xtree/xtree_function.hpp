#ifndef FT_XTREE_FUNCTION
# define FT_XTREE_FUNCTION

#include "xtree.hpp"

namespace ft
{   
    template <class Tree_traits>
    typename Tree<Tree_traits>::size_type Tree<Tree_traits>::size() const
    {
        return (Size);
    }

    template <class Tree_traits>
    typename Tree<Tree_traits>::size_type Tree<Tree_traits>::max_size() const
    {
        return (Tree::Alval.max_size());
    }

    template <class Tree_traits>
    bool Tree<Tree_traits>::empty() const
    {
        std::cout << size() << std::endl;
        return (size() == 0);
    }

    template <class Tree_traits>
    typename Tree<Tree_traits>::key_compare Tree<Tree_traits>::key_comp() const
    {
        return (Tree_traits::comp);
    }

    template <class Tree_traits>
    typename Tree<Tree_traits>::value_compare Tree<Tree_traits>::value_comp() const
    {
        return (value_compare(key_comp()));
    }
}

#endif