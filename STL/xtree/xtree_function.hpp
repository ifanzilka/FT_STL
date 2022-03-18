/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtree_function.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:15:20 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:15:21 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    /* Представляет собой (для определения порядка) bool operator (key x, key y) */
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

    template <class Tr>
    void Tree<Tr>::Copy(const Myt &X)
    {
		Root() = Copy(X.Root(), Head);
		Size = X.size();
		if (!Isnil(Root()))
		{
			Lmost() = Min(Root());
			Rmost() = Max(Root());
		}
        else
        {
            Lmost() = Head;
            Rmost() = Head;
        }
    }

    template <class Tr>
	typename Tree<Tr>::Nodeptr Tree<Tr>::Copy(Nodeptr X, Nodeptr P)
	{
		Nodeptr R = Head;
		if (!Isnil(X))
		{
			Nodeptr Y = Buynode(P, Color(X));
			try
			{
				Consval(&Value(Y), Value(X));
			}
			catch (...)
			{
				Freenode(Y);
				Erase(R);
				throw;
			}
			Left(Y) = Head, Right(Y) = Head;
			if (Isnil(R))
				R = Y;
			try
			{
				Left(Y) = Copy(Left(X), Y);
				Right(Y) = Copy(Right(X), Y);
			}
			catch (...)
			{
				Erase(R);
				throw;
			}
		}
		return (R);
	}


}

#endif