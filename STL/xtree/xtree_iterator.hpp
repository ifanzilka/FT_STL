#ifndef FT_XTREE_ITERATOR
# define FT_XTREE_ITERATOR

#include "xtree.hpp"

namespace ft
{

    /* Конструктор */
    template <class Tree_traits>
    typename Tree<Tree_traits>::iterator(): Ptr(0)
    {
        
    }

    /* Конструктор */
    template <class Tree_traits>
    typename Tree<Tree_traits>::iterator(Nodeptr P): Ptr(0)
    {
        
    }

    /* Class Iterator */
    class iterator;
    friend class iterator;
    class iterator: public Bidit<value_type, difference_type, Tptr, Reft>
    {   
        typedef Bidit<value_type, difference_type, Tptr, Reft>  Mybase;
        typedef typename Mybase::iterator_category              iterator_category;
        typedef typename Mybase::value_type                     value_type;
        typedef typename Mybase::difference_type                difference_type;
        typedef typename Mybase::pointer                        pointer;
        typedef typename Mybase::reference                      reference;


        /* Constructor */
        iterator(): Ptr(0){};

        /* Constructor */
        iterator(Nodeptr P): Ptr(P) {};


        /* Overload operator */
        reference operator*() const {return (Value(Ptr))};
        
        Tptr operator->() const;

        iterator& operator++();

        iterator operator*(int);

        iterator& operator-();

        iterator operator--(int);


        bool operator==(const iterator X) const;

        bool operator!=(const iterator X) const;

        void Dec();

        void Inc();

        Nodeptr Mynode() const;

    protected:
        Nodeptr Ptr;    
    };
}

#endif