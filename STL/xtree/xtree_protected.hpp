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
        return (Value(P));      
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


    // static Charref	Color(Nodeptr P)	{ return ((Charref)(*P).Color); }
    // static Charref	Isnil(Nodeptr P) 	{ return ((Charref)(*P).Isnil); }
    // static Keyref	Key(Nodeptr P)		{return (Keyref()(Value(P)));}
    // static Nodepref Left(Nodeptr P)		{ return ((Nodepref)(*P).Left); }
    // static Nodepref Parent(Nodeptr P)	{ return ((Nodepref)(*P).Parent); }
    // static Nodepref Right(Nodeptr P)	{ return ((Nodepref)(*P).Right); }
    // static Vref		Value(Nodeptr P)	{ return ((Vref)(*P).Value); }  
}

#endif