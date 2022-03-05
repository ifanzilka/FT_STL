#ifndef FT_XTREE_COSTRUCTOR
# define FT_XTREE_COSTRUCTOR

#include "xtree.hpp"

namespace ft
{
    template <class Tree_traits>
    Tree<Tree_traits>::Tree(const key_compare &Parg, const allocator_type& Al): Mybase(Parg, Al)
    {
        //Init();
    }

    template <class Tree_traits>
    Tree<Tree_traits>::Tree(const value_type *First, const value_type *Last, const key_compare &Parg, const allocator_type &Al): Mybase(Parg, Al)
    {
        //Init();
        //insert(First, Last);
    }

    template <class Tree_traits>
    Tree<Tree_traits>::Tree(const Myt & X): Mybase(X.key_camp(), X.get_allocator())
    {
        //Init();
		//Copy(X);
    }

    template <class Tree_traits>
    Tree<Tree_traits>::~Tree()
    {
		// erase(begin(), end());
		// FreeNode(Head);
		
        // Head = 0;
        // Size = 0;
    }
}

#endif