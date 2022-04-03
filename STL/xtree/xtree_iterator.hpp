/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtree_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:15:31 by bmarilli          #+#    #+#             */
/*   Updated: 2022/04/03 19:27:54 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XTREE_ITERATOR
# define FT_XTREE_ITERATOR

#include "xtree.hpp"
#include "../iterator/iterator.hpp"

namespace ft
{
    template <class tree_traits>
    class tree_iterator
	{
    public:
        //tree_traits tr;

        typedef typename Tree<tree_traits>::value_type  value_type;
        typedef typename Tree<tree_traits>::Dift        difference_type;
        typedef typename Tree<tree_traits>::Tptr        Tptr;
        typedef typename Tree<tree_traits>::Reft        Reft;


        typedef Bidit<value_type, difference_type, Tptr, Reft>  Mybase;
        typedef typename Mybase::iterator_category              iterator_category;
        typedef typename Mybase::pointer                        pointer;
        typedef typename Mybase::reference                      reference;

        typedef typename Tree<tree_traits>::Nodeptr			    Nodeptr;
       

        /* Constructor */
        tree_iterator(): Ptr(0)
        {
            
        };

        /* Constructor */
        tree_iterator(Nodeptr P): Ptr(P) 
        {
        
        };
        
        /*Констркутор с другим итератором */
        template<class Other_tree_traits>
        tree_iterator(const tree_iterator<Other_tree_traits> & other)
        {
            Ptr = reinterpret_cast<Nodeptr> (other.Ptr);
        };
    
        /* Overload operator */
        reference operator*() const 
        {
            return (Tree<tree_traits>::Value(Ptr));
        }
        
        Tptr operator->() const {return (&**this);}

        /* ++iterator */
        tree_iterator& operator++()
        {
            Inc();
            return(*this);
        }
        
        /* iterator++ */
        tree_iterator operator++(int)
        {
            tree_iterator Tmp = *this;
            
            ++*this;
            return (Tmp);
        }

        /* --iterator */
        tree_iterator& operator--()
        {
            Dec();
            return (*this);
        }

        /* iterator-- */
        tree_iterator operator--(int)
        {
            tree_iterator Tmp = *this;
            
            --*this;
            return (Tmp);
        }


        bool operator==(const tree_iterator X) const 
        {
            return (Ptr == X.Ptr);
        }

        bool operator!=(const tree_iterator X) const
        {
            return !(*this == X);
        }

        void Dec()
        {
            if (Tree<tree_traits>::Isnil(Ptr))
                Ptr = Tree<tree_traits>::Right(Ptr);
            else if (!Tree<tree_traits>::Isnil(Tree<tree_traits>::Left(Ptr)))
            {   
                /* Крайний правый элемент  левого поддерева*/
                Ptr = Tree<tree_traits>::Max(Tree<tree_traits>::Left(Ptr));
            }
            else
            {
                Nodeptr P;

                while (!Tree<tree_traits>::Isnil(P = Tree<tree_traits>::Parent(Ptr)) && Ptr == Tree<tree_traits>::Left(P))
                {
                    Ptr = P;
                }
                if (!Tree<tree_traits>::Isnil(P))
                {
                    Ptr = P;
                }
            }
        }

        void Inc()
        {
            if (Tree<tree_traits>::Isnil(Ptr))
                ;
                
            else if (!Tree<tree_traits>::Isnil(Tree<tree_traits>::Right(Ptr)))
            {   
                /* Крайний левый элемент правого поддерева*/
                Ptr = Tree<tree_traits>::Min(Tree<tree_traits>::Right(Ptr));
            }
            else
            {
                Nodeptr P;

                /* ищем роддительский узел правого поддерева */
                while (!Tree<tree_traits>::Isnil(P = Tree<tree_traits>::Parent(Ptr)) && Ptr == Tree<tree_traits>::Right(P))
                {
                    Ptr = P;
                }
                Ptr = P;
            }
        }

        Nodeptr Mynode() const
        {
            return (Ptr);
        }

    public:
        Nodeptr Ptr;   

    };
}

#endif