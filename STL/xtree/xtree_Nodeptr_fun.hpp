/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtree_Nodeptr_fun.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:15:37 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:15:38 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    template <class Tr>
    typename Tree<Tr>::Nodeptr Tree<Tr>::Max(Nodeptr P)
    {
        while (!Isnil(Right(P)))
			    P = Right(P);
		return (P);
    }

    template <class Tr>
    typename Tree<Tr>::Nodeptr Tree<Tr>::Min(Nodeptr P)
    {
        while (!Isnil(Left(P)))
			P = Left(P);
		return (P);        
    }
    
}

#endif