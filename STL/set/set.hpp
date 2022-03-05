#ifndef FT_SET
# define FT_SET

#include <iostream>

/* Kernel root */
#include "../xtree/xtree.hpp"


/* 517 */
namespace ft
{

    /* Traits позволяет не писаит длинный список параметров при инициалиазции Tree */
    template <class K, class Pr, class Al, bool Mfl>
	class Tset_traits
    {
    public:
        typedef K   key_type;
        typedef K   value_type;
        typedef Pr  key_compare;
        
        typedef typename Al::template rebind<value_type>::other allocator_type;

        enum
        {
            /* False если set/map */
            /* True если multiset/multimap */
            Multi = Mfl
        };

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


    /* Шаблоны для set Pr- для сравнивания A -> аллокатор */
    template<class K, class Pr = std::less<K>, class A = std::allocator<K> >
    class set : public ft::Tree< Tset_traits<K, Pr, A, false > >
    {
    public:
        typedef set<K, Pr, A>                           Myt;
        typedef Tree< Tset_traits<K, Pr, A, false> >    Mybase;
        typedef K                                       key_type;   /* Тип того что мы храним */
        typedef Pr                                      key_compare;
        typedef typename Mybase::value_compare          value_compare;
        typedef typename Mybase::allocator_type         allocator_type;
        typedef typename Mybase::size_type              size_type;
        typedef typename Mybase::difference_type        difference_type;
        typedef typename Mybase::pointer                pointer;
        typedef typename Mybase::const_pointer          const_pointer;
        typedef typename Mybase::iterator               iterator;
        typedef typename Mybase::const_iterator         const_iterator;
        typedef typename Mybase::reverse_iterator       reverse_iterator;
        typedef typename Mybase::const_reverse_iterator const_reverse_iterator;
        typedef typename Mybase::value_type             value_type;


        /*****************************************************/
        /*                      Constructors                 */
        /*****************************************************/

        set();

        explicit set(const key_compare& Pred);

        set(const key_compare& Pred, const allocator_type &Al);

        template<class It>
        set(It F, It L);

        template<class It>
        set(It F, It L, const key_compare &Pred);

        template<class It>
        set(It F, It L, const key_compare &Pred, const allocator_type &Al);

    };
}

#include "set_constructor.hpp"

#endif