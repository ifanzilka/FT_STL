#ifndef FT_XTREE_MODIFERS
# define FT_XTREE_MODIFERS

#include "xtree.hpp"

namespace ft
{
    /* Tr-> Tree_traits */

    template <class Tr>
    typename Tree<Tr>::Pairib Tree<Tr>::insert(const value_type & V)
    {
        Nodeptr X = Root();
        Nodeptr Y = Head;
        bool Addleft = true;

        while (!Isnil(X))
        {
            Y = X;
            //Addleft = comp(Kfn()(V), Key(X));
            
            if (Addleft)
                X = Left(X);
            else
                X = Right(X);
        }

        if (Tr::Multi)
        {
            return Pairib(Insert(true, Y, V), true);
        }
        else
        {
            //iterator P  = iterator(Y);

            if (!Addleft)
                ;
            // else if (P == begin())
            //     return Pairib(Insert(true, Y, V), true);
            // else
            //     --P;

            // if (comp(Key(P.Mynode()), Kfn()(V) ))
            //     return Pairib(Insert(Addleft, Y, V), true);
            // else
            //     return Pairib(P, false);
        }
    }

}

#endif