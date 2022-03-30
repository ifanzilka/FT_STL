/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtree_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <ifanzilka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:15:31 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/30 16:49:39 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XTREE_ITERATOR
# define FT_XTREE_ITERATOR

#include "xtree.hpp"
#include "../iterator/iterator.hpp"

namespace ft
{
    template <class tree_traits>
    class tree_iterator: public ft::Bidit< typename Tree<tree_traits>::value_type, 
 				typename Tree<tree_traits>::Dift,
				typename Tree<tree_traits>::Tptr,
				typename Tree<tree_traits>::Reft>
	{
    public:

        typedef typename Tree<tree_traits>::value_type  value_type;
        typedef typename Tree<tree_traits>::Dift        difference_type;
        typedef typename Tree<tree_traits>::Tptr        Tptr;
        typedef typename Tree<tree_traits>::Reft        Reft;


        typedef Bidit<value_type, difference_type, Tptr, Reft>  Mybase;
        typedef typename Mybase::iterator_category              iterator_category;
        typedef typename Mybase::pointer                        pointer;
        typedef typename Mybase::reference                      reference;

        typedef typename Tree<tree_traits>::Nodeptr			    Nodeptr;
       
        //typedef  Tree<tree_traits>::Value               Value;

        /* Constructor */
        tree_iterator(): Ptr(0){};

        /* Constructor */
        tree_iterator(Nodeptr P): Ptr(P) 
        {
        
        };

        /*Констркутор с другим итератором */
        // template<class Tree_traits>
        // tree_iterator(const tree_iterator<Tree_traits> & other)//: Ptr(other.Ptr)
        // {
        //     this->Ptr = other.Ptr;
        
        //     //this->Ptr = other.Ptr;
        //     std::cout << "tyt\n";
        // };
            
        // tree_iterator &operator=(const tree_iterator &obj)
        // {
        //     node = obj.node;
            
        //     return *this; 
        // }

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