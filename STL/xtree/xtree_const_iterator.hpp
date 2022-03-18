/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtree_const_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:15:13 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:15:14 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XTREE_CONST_ITERATOR
# define FT_XTREE_CONST_ITERATOR

#include "xtree.hpp"
#include "../iterator/iterator.hpp"

namespace ft
{
    template <class tree_traits>
    class  const_tree_iterator: public Bidit< typename Tree<tree_traits>::value_type, 
 				typename Tree<tree_traits>::Dift,
				typename Tree<tree_traits>::Ctptr,
				typename Tree<tree_traits>::const_reference>
	{
    public:

        typedef typename Tree<tree_traits>::value_type              value_type;
        typedef typename Tree<tree_traits>::Dift                    difference_type;
        typedef typename Tree<tree_traits>::Ctptr                   Ctptr;
        typedef typename Tree<tree_traits>::const_reference         const_reference;


        typedef Bidit<value_type, difference_type, Ctptr, const_reference>  Mybase;
        typedef typename Mybase::iterator_category              iterator_category;
        typedef typename Mybase::pointer                        pointer;
        typedef typename Mybase::reference                      reference;

        typedef typename Tree<tree_traits>::Nodeptr			    Nodeptr;
       
        //typedef  Tree<tree_traits>::Value               Value;

        /* Constructor */
        const_tree_iterator(): Ptr(0){};

        /* Constructor */
        const_tree_iterator(Nodeptr P): Ptr(P) {};

        const_tree_iterator(const typename Tree<tree_traits>::iterator X): Ptr(X.Mynode())
        {
            
        };

        /* Overload operator */
        const_reference operator*() const 
        {
            return (Tree<tree_traits>::Value(Ptr));
        }
        
        Ctptr operator->() const {return (&**this);}

        /* ++iterator */
        const_tree_iterator& operator++()
        {
            Inc();
            return(*this);
        }
        
        /* iterator++ */
        const_tree_iterator operator++(int)
        {
            const typename Tree<tree_traits>::iterator Tmp = *this;
            
            ++*this;
            return (Tmp);
        }

        /* --iterator */
        const_tree_iterator& operator--()
        {
            Dec();
            return (*this);
        }

        /* iterator-- */
        const_tree_iterator operator--(int)
        {
            const typename Tree<tree_traits>::iterator Tmp = *this;
            
            --*this;
            return (Tmp);
        }


        bool operator==(const const_tree_iterator X) const 
        {
            return (Ptr == X.Ptr);
        }

        bool operator!=(const const_tree_iterator X) const
        {
            return !(*this == X);
        }

        void Dec()
        {
            if (Tree<tree_traits>::Isnil(Ptr))
                Ptr = Tree<tree_traits>::Right(Ptr);
            else if (!Tree<tree_traits>::Isnil(Tree<tree_traits>::Left(Ptr)))
            {   
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
                Ptr = Tree<tree_traits>::Min(Tree<tree_traits>::Right(Ptr));
            }
            else
            {
                Nodeptr P;

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

    protected:
        Nodeptr Ptr;   

    };
}


#endif