#ifndef FT_SET
# define FT_SET

#include <iostream>

/* Kernel root */
#include "../STL/xtree/xtree.hpp"

namespace ft
{

    /* Traits позволяет не писаит длинный список параметров при инициалиазции Tree */
    template <class K, class Pr, class Al>
	class Tset_traits
    {
    public:
        typedef K   key_type;
        typedef K   value_type;
        typedef Pr  key_compare;
        
        typedef typename Al::template rebind<value_type>::other allocator_type;

        Tset_traits(): comp(), v_comp() 
        {

        }
        
        Tset_traits(Pr Parg): comp (Parg), v_comp() 
        {

        }
        
        typedef key_compare value_compare;

        struct Kfn
        {
            const K& operator() (const value_type & X ) const
            {
                return (X);
            }
        };

        key_compare     comp;
        value_compare   v_comp;
	};


    /* Шаблоны для set*/
    template<class K, class Pr = std::less<K>, class A = std::allocator<K> >
    class set : public Tree< Tset_traits< K, Pr, A > >
    {

    };

}

#endif