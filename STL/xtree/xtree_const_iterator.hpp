#ifndef FT_XTREE_CONST_ITERATOR
# define FT_XTREE_CONST_ITERATOR

#include "xtree.hpp"

namespace ft
{
    // /* Class const Iterator */
    // class const_iterator;
    // friend class const_iterator;
    // class const_iterator: public Bidit<value_type, difference_type, Ctptr, const_reference>
    // {   
    //     typedef Bidit<value_type, difference_type, Ctptr, const_reference>  Mybase;
    //     typedef typename Mybase::iterator_category                          iterator_category;
    //     typedef typename Mybase::value_type                                 value_type;
    //     typedef typename Mybase::difference_type                            difference_type;
    //     typedef typename Mybase::pointer                                    pointer;
    //     typedef typename Mybase::reference                                  reference;


    //     /* Constructor */
    //     const_iterator();

    //     /* Constructor */
    //     const_iterator(Nodeptr P);

    //     const_iterator(const typename Tree<Tree_traits>::iterator X);

    //     /* Overload operator */
    //     const_reference operator*() const ;
        
    //     Ctptr operator->() const;

    //     const_iterator &operator++();

    //     const_iterator operator++(int);

    //     const_iterator &operator--();

    //     const_iterator operator--(int);


    //     bool operator==(const const_iterator X) const;

    //     bool operator!=(const const_iterator X) const;

    //     void Dec();

    //     void Inc();

    //     Nodeptr Mynode() const;

    // protected:
    //     Nodeptr Ptr;    
    // };
}

#endif