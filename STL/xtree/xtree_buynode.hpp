#ifndef FT_XTREE_BUYNODE
# define FT_XTREE_BUYNODE

#include "xtree.hpp"

namespace ft
{
    /* Carg -> Color */


    template <class Tree_traits>
    /* Выделяет память под новую ноду, задает родителя и цвет ноде */
    typename Tree<Tree_traits>::Nodeptr Tree<Tree_traits>::Buynode(Nodeptr Parg, char Carg)
    {
        /* Выделили память под голову дерева */
        Nodeptr S = Tree::Alnod.allocate(1, (void *)0);

        /* Взяли левый элемент дерева и вызвали конструктор с null */
        Tree::Alptr.construct(&Left(S), nullptr);
        
        /* Взяли левый элемент дерева и вызвали конструктор с null */
		Tree::Alptr.construct(&Right(S), nullptr);
		
        /* Взяли у ноды и вызвали конструктор с нодой (задали родителя) */
        Tree::Alptr.construct(&Parent(S), Parg);

        /* Задали цвет ноде */
        Color(S) = Carg;
		Isnil(S) = false;
		return (S);
    }
}

#endif