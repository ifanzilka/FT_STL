/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtree_protected.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <ifanzilka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:15:41 by bmarilli          #+#    #+#             */
/*   Updated: 2022/04/03 02:16:56 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XTREE_PROTECTED
# define FT_XTREE_PROTECTED

#include "xtree.hpp"

namespace ft
{
    /* Tr-> Tree_traits */

    template <class Tr>
    /* Возвращает цвет ноды */
    typename Tree<Tr>::Charref Tree<Tr>::Color(Nodeptr P)
    {
        return ((Charref)(*P).Color);
    }

    template <class Tr>
    typename Tree<Tr>::Charref Tree<Tr>::Isnil(Nodeptr P)
    {
        return ((Charref)(*P).Isnil);        
    }

    /* Получаем Ноду */
    template <class Tr>
    typename Tree<Tr>::Keyref Tree<Tr>::Key(Nodeptr P)
    {
        return (Tr::GetKey(Value(P)));      
    }

    template <class Tr>
    /* Возвращает левую ноду */
    typename Tree<Tr>::Nodepref Tree<Tr>::Left(Nodeptr P)
    {
        return ((Nodepref)(*P).Left);        
    }

    template <class Tr>
    /* Возвращает родительскую ноду */
    typename Tree<Tr>::Nodepref Tree<Tr>::Parent(Nodeptr P)
    {
        return ((Nodepref)(*P).Parent);        
    }

    template <class Tr>
    /* Возвращает правую ноду */
    typename Tree<Tr>::Nodepref Tree<Tr>::Right(Nodeptr P)
    {
        return ((Nodepref)(*P).Right);        
    }

    template <class Tr>
    /* Из ноды получаю значение */
    typename Tree<Tr>::Vref Tree<Tr>::Value(Nodeptr P)
    {
        return ((Vref)(*P).Value);        
    }


    /* возвращаю новую голову после балансировки  (ишу первый элемент который больше) */
    template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr Tree<Tree_traits>::Lbound(const key_type &Kv) const
	{
        /* Беру родителя головы */
		Nodeptr X = Root();
		Nodeptr Y = Head;

        /*  Пока не пустое поддерево  */
		while (!(Isnil(X)))
		{
            /* если меньше наш корень меньше */
			if (Tree_traits::comp(Key(X), Kv))
            {
				X = Right(X);
            }
            else
            {
                /* если больше наш корень больше */
                /* то присваеваем новую голову */
				Y = X;
                X = Left(X);
            }
		}
        
        /* возвращаю новую голову */
		return (Y);
	}

    /* возвращаю новую голову после балансировки  (ишу первый элемент который меньше) */
    template <class Tr>
	typename Tree<Tr>::Nodeptr Tree<Tr>::Ubound(const key_type &Kv) const
	{
	    Nodeptr X = Root();
		Nodeptr Y = Head;
        
		while (!Isnil(X))
		{
			if (Tr::comp(Kv, Key(X)))
            {
				Y = X;
                X = Left(X);
            }
            else
            {
				X = Right(X);
            }
		}
        
        /* возвращаю новую голову */
		return (Y);
	}


    // static Charref	Color(Nodeptr P)	{ return ((Charref)(*P).Color); }
    // static Charref	Isnil(Nodeptr P) 	{ return ((Charref)(*P).Isnil); }
    // static Keyref	Key(Nodeptr P)		{return (Keyref()(Value(P)));}
    // static Nodepref Left(Nodeptr P)		{ return ((Nodepref)(*P).Left); }
    // static Nodepref Parent(Nodeptr P)	{ return ((Nodepref)(*P).Parent); }
    // static Nodepref Right(Nodeptr P)	{ return ((Nodepref)(*P).Right); }
    // static Vref		Value(Nodeptr P)	{ return ((Vref)(*P).Value); }  
}

#endif