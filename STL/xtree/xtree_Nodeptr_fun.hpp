#ifndef FT_XTREE_NODEPTR_FUN
# define FT_XTREE_NODEPTR_FUN

#include "xtree.hpp"

namespace ft
{
    /* Tr -> Tree_traits */

    /* от Ноды возвращаю родительскую ветвь */
    template <class Tr>
    typename Tree<Tr>::Nodeptr& Tree<Tr>::Root()
    {
        return (Parent(Head));
    }

    /* от Ноды возвращаю родительскую ветвь */
    template <class Tr>
    typename Tree<Tr>::Nodeptr& Tree<Tr>::Root() const
    {
        return (Parent(Head));
    }

    /* от Ноды возвращаю левую ветвь */
    template <class Tr>
    typename Tree<Tr>::Nodeptr& Tree<Tr>::Lmost()
    {
        return (Left(Head));
    }

    /* от Ноды возвращаю левую ветвь */
    template <class Tr>
    typename Tree<Tr>::Nodeptr& Tree<Tr>::Lmost() const
    {
        return (Left(Head));
    }

    /* от Ноды возвращаю правую ветвь */
    template <class Tr>
    typename Tree<Tr>::Nodeptr& Tree<Tr>::Rmost()
    {
        return (Right(Head));
    }

    /* от Ноды возвращаю правую ветвь */
    template <class Tr>
    typename Tree<Tr>::Nodeptr& Tree<Tr>::Rmost() const
    {
        return (Right(Head));
    }
}

#endif