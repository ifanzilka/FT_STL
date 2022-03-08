#ifndef FT_XTREE_COSTRUCTOR
# define FT_XTREE_COSTRUCTOR

#include "xtree.hpp"

namespace ft
{
    /* Tr -> Tree_traits*/
    template <class Tr>
    Tree<Tr>::Tree(const key_compare &Parg, const allocator_type& Al): Mybase(Parg, Al)
    {
        Init();
    }

    template <class Tr>
    Tree<Tr>::Tree(const value_type *First, const value_type *Last, const key_compare &Parg, const allocator_type &Al): Mybase(Parg, Al)
    {
        Init();
        //insert(First, Last);
    }

    template <class Tr>
    Tree<Tr>::Tree(const Myt & X): Mybase(X.key_camp(), X.get_allocator())
    {
        Init();
		//Copy(X);
    }

    template <class Tr>
    Tree<Tr>::~Tree()
    {
		erase(begin(), end());
		Freenode(Head);
		
        Head = 0;
        Size = 0;
    }


    template <class Tr>
    /* По указателю вызываю конструктор и кладу значение */
    void Tree<Tr>::Consval(Tptr P, const value_type &V)
    {
        this->Alval.construct(P, V);
    }

    template <class Tr>
    typename Tree<Tr>::Myt& Tree<Tr>::operator=(const Myt &x)
    {
        if (this != &x)
        {
            erase(begin(), end());  
            Tr::comp = x.comp;
            Copy(x);
        }
        return (*this);
    }
}

#endif