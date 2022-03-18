/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtree_rotate.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:15:45 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:15:45 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XTREE_ROTATE
# define FT_XTREE_ROTATE

#include "xtree.hpp"

namespace ft
{
    /* Tr -> Tree Traits */
    
    template <class Tr>
    void Tree<Tr>::Lrotate(Nodeptr X)
    {
        Nodeptr Y = Right(X);
        
        Right(X) = Left(Y);
        
        if (!Isnil(Left(Y)))
            Parent(Left(Y)) = X;
        
        Parent(Y) = Parent(X);
        
        if (X == Root())
            Root() = Y;
        else if (X == Left(Parent(X)))
            Left(Parent(X)) = Y;
        else
            Right(Parent(X)) = Y;
        
        Left(Y) = X;
        Parent(X) = Y;
    }

    template <class Tr>
    void Tree<Tr>::Rrotate(Nodeptr X)
    {
        Nodeptr Y = Left(X);
        
        Left(X) = Right(Y);
        
        if (!Isnil(Right(Y)))
            Parent(Right(Y)) = X;
        
        Parent(Y) = Parent(X);
        
        if (X == Root())
            Root() = Y;
        else if (X == Right(Parent(X)))
            Right(Parent(X)) = Y;
        else
            Left(Parent(X)) = Y;
        
        Right(Y) = X;
        Parent(X) = Y; 
    }
}

#endif