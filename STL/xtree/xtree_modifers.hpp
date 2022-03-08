#ifndef FT_XTREE_MODIFERS
# define FT_XTREE_MODIFERS

#include "xtree.hpp"
#include "../set/set.hpp"

namespace ft
{
    /* Tr-> Tree_traits */
    
    /* Page 528 */
    template <class Tr>
    // typename Tree<Tr>::Pairib 
    typename Tree<Tr>::Pairib Tree<Tr>::insert(const value_type & V)
    {
        Nodeptr X = Root();
        Nodeptr Y = Head;
        bool Addleft = true;

        //std::cout << "Call insert(const value_type & V)\n";

        Keyref A = Key(X);

		Addleft = this->comp(this->GetKey(V), Key(X));
        while (!Isnil(X))
        {
			Y = X;

			Addleft = Tr::comp(Tr::GetKey(V), Key(X));
			if (Addleft)
                X = Left(X);
            else
                X = Right(X);
		}
            
		if (Tr::Multi)
		{
			return (Pairib(Insert(true, Y, V), true));
		}
		else
		{
			iterator P = iterator(Y);
			if (!Addleft)
				;
			else if (P == begin())
			{
				return (Pairib(Insert(true, Y, V), true));
			}
			else
				--P;
			if (Tr::comp(Key(P.Mynode()), Tr::GetKey(V)))
				return (Pairib(Insert(Addleft, Y, V), true));
			else;
				return (Pairib(P, false));
		}
    }


    template <class Tr>
    //typename Tree<Tr>::iterator 
    typename Tree<Tr>::iterator Tree<Tr>::Insert(bool Addleft, Nodeptr Y, const value_type &V)
   	{
	
		//std::cout << "Call iterator Tree<Tr>::Insert(bool Addleft, Nodeptr Y, const value_type &V) \n";
	
        if (max_size() - 1 <= Size)
			throw std::length_error("map/set<T> too long");

        Nodeptr Z = Buynode(Y, Red);

		//return (iterator(Z));
		Left(Z) = Head;
        Right(Z) = Head;
		
        try
		{
			/* В ноду положил значение */
			Consval(&Value(Z), V);
		}
		catch (...)
		{
			//Freenode(Z);
			throw;
		}
		++Size;

		if (Y == Head)
		{
			Root() = Z;
			Lmost() = Z;
            Rmost() = Z;
		}
		else if (Addleft)
		{
			Left(Y) = Z;
			if (Y == Lmost())
				Lmost() = Z;
		}
		else
		{
			Right(Y) = Z;
			if (Y == Rmost())
				Rmost() = Z;
		}

		for (Nodeptr X = Z; Color(Parent(X)) == Red; )
		{
			if (Parent(X) == Left(Parent(Parent(X))))
			{
				Y = Right(Parent(Parent(X)));
				if (Color(Y) == Red)
				{
					Color(Parent(X)) = Black;
					Color(Y) = Black;
					Color(Parent(Parent(X))) = Red;
					X = Parent(Parent(X));
				}
				else
				{
					if (X == Right(Parent(X)))
					{
						X = Parent(X);
						Lrotate(X);
					}
					Color(Parent(X)) = Black;
					Color(Parent(Parent(X))) = Red;
					Rrotate(Parent(Parent(X)));
				}
			}
			else
			{
				Y = Left(Parent(Parent(X)));
				if (Color(Y) == Red)
				{
					Color(Parent(X)) = Black;
					Color(Y) = Black;
					Color(Parent(Parent(X))) = Red;
					X = Parent(Parent(X));
				}
				else
				{
					if (X == Left(Parent(X)))
					{
						X = Parent(X);
						Rrotate(X);
					}
					Color(Parent(X)) = Black;
					Color(Parent(Parent(X))) = Red;
					Lrotate(Parent(Parent(X)));
				}
			}
		}
		Color(Root()) = Black;
		return (iterator(Z));
	}
}

#endif