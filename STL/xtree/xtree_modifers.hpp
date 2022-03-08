#ifndef FT_XTREE_MODIFERS
# define FT_XTREE_MODIFERS

/* swap*/
#include "../algorithm/algorithm.hpp"

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
			Freenode(Z);
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

	template <class Tr>
	typename Tree<Tr>::iterator Tree<Tr>::erase(iterator F, iterator L)
	{
		if (size() == 0 || F != begin() || L != end())
		{
			while (F != L)
			{
				erase(F++);
			}
			return (F);
		}
		else
		{	
			Erase(Root());
			Root() = Head;
			Size = 0;
			Lmost() = Head;
			Rmost() = Head;
			return (begin());
		}
	}

	template <class Tr>
	typename Tree<Tr>::iterator Tree<Tr>::erase(iterator P)
	{
		std::cout << GREEN"Call iterator Tree<Tr>::erase(iterator P)\n"F_NONE;
		
		if (Isnil(P.Mynode()))
			throw std::out_of_range("map/set<T> iterator");
		
		Nodeptr X, XPar;
		Nodeptr Y = (P++).Mynode();
		Nodeptr Z = Y;

		if (Isnil(Left(Y)))
			X = Right(Y);
		else if (Isnil(Right(Y)))
			X = Left(Y);
		else
			Y = Min(Right(Y)), X = Right(Y);
		if (Y == Z)
		{
			XPar = Parent(Z);
			if (!Isnil(X))
				Parent(X) = XPar;

			if (Root() == Z)
				Root() = X;
			else if (Left(XPar) == Z)
				Left(XPar) = X;
			else
				Right(XPar) = X;

			if (Lmost() != Z)
				;
			else if (Isnil(Right(Z)))
				Lmost() = XPar;
			else
				Lmost() = Min(X);

			if (Rmost() != Z)
				;
			else if (Isnil(Left(Z)))
				Rmost() = XPar;
			else
				Rmost() = Max(X);
		}
		else
		{
			Parent(Left(Z)) = Y;
			Left(Y) = Left(Z);
			if (Y == Right(Z))
				XPar = Y;
			else
			{
				XPar = Parent(Y);
				if (!Isnil(X))
					Parent(X) = XPar;
				Left(XPar) = X;
				Right(Y) = Right(Z);
				Parent(Right(Z)) = Y;
			}
			if (Root() == Z)
				Root() = Y;
			else if (Left(Parent(Z)) == Z)
				Left(Parent(Z)) = Y;
			else
				Right(Parent(Z)) = Y;
			Parent(Y) = Parent(Z);
			//Tree<Tr> &X
			ft::swap(Color(Y), Color(Z));
		}
		if (Color(Z) == Black)
		{
			for (; X != Root() && Color(X) == Black; XPar = Parent(X))
				if (X == Left(XPar))
				{
					Nodeptr W = Right(XPar);
					if (Color(W) == Red)
					{
						Color(W) = Black;
						Color(XPar) = Red;
						Lrotate(XPar);
						W = Right(XPar);
					}
					if (Isnil(W))
						X = XPar;
						// shouldn't happen
					else if (Color(Left(W)) == Black && Color(Right(W)) == Black)
					{
						Color(W) = Red;
						X = XPar;
					}
					else
					{
						if (Color(Right(W)) == Black)
						{
							Color(Left(W)) = Black;
							Color(W) = Red;
							Rrotate(W);
							W = Right(XPar);
						}
						Color(W) = Color(XPar);
						Color(XPar) = Black;
						Color(Right(W)) = Black;
						Lrotate(XPar);
						break;
					}
				}
				else
				{
					Nodeptr W = Left(XPar);
					if (Color(W) == Red)
					{
						Color(W) = Black;
						Color(XPar) = Red;
						Rrotate(XPar);
						W = Left(XPar);
					}
					if (Isnil(W))
						X = XPar;
						// shouldn't happen
					else if (Color(Right(W)) == Black && Color(Left(W)) == Black)
					{
						Color(W) = Red;
						X = XPar;
					}
					else
					{
						if (Color(Left(W)) == Black)
						{
							Color(Right(W)) = Black;
							Color(W) = Red;
							Lrotate(W);
							W = Left(XPar);
						}
						Color(W) = Color(XPar);
						Color(XPar) = Black;
						Color(Left(W)) = Black;
						Rrotate(XPar);
						break;
					}
				}
			Color(X) = Black;
		}
		Destval(&Value(Z));
		Freenode(Z);
		if (0 < Size)
			--Size;
		return (P);
	}

	/*****************************************************/
	/*              Protected                            */
	/*****************************************************/
	
	template <class Tr>
	void Tree<Tr>::Erase(Nodeptr X)
	{
		
		for (Nodeptr Y = X; !Isnil(Y); X = Y)
		{
			Erase(Right(Y));
			Y = Left(Y);
			Destval(&Value(X));
			Freenode(X);
		}
	}

	/* Вызываю деструктор по указателю */
	template <class Tr>
	void Tree<Tr>::Destval(Tptr P)
	{
		this->Alval.destroy(P);
	}

	/* Вызываю деструткоры у ноды и особождаю память */
	template <class Tr>
    void Tree<Tr>::Freenode(Nodeptr S)
	{
		this->Alptr.destroy(&Parent(S));
		this->Alptr.destroy(&Right(S));
		this->Alptr.destroy(&Left(S));
		this->Alnod.deallocate(S, 1);
	}

}

#endif