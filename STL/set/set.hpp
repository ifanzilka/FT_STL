#ifndef FT_SET
# define FT_SET

//#include <iostream>

/* Свойства */
#include "tset_traits.hpp"

/* Kernel root */
#include "../xtree/xtree.hpp"

/* Include less */
#include "../functional/functional.hpp"


/* 517 */
namespace ft
{

    /* Шаблоны для set Pr- для сравнивания A -> аллокатор */
    template<class K, class Pr = ft::less<K>, class A = std::allocator<K> >
    class set : public Tree< ft::Tset_traits<K, Pr, A, false > >
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

        set(): Mybase(key_compare(), allocator_type())
        {
        
        }

        explicit set(const key_compare& Pred): Mybase(Pred, allocator_type())
        {
        
        }

        set(const key_compare& Pred, const allocator_type &Al): Mybase(Pred, Al)
        {
        
        }

        template<class It>
        set(It F, It L): Mybase(key_compare(), allocator_type())
        {
            for (; F != L; ++F)
            {
                Tree< Tset_traits<K, Pr, A, false > >::insert(*F);
            }  
        }

        template<class It>
        set(It F, It L, const key_compare &Pred): Mybase(Pred, allocator_type())
        {
            for (; F != L; ++F)
            {
                Tree< Tset_traits<K, Pr, A, false > >::insert(*F);
            }        
        }

        template<class It>
        set(It F, It L, const key_compare &Pred, const allocator_type &Al): Mybase(Pred, Al)
        {
            for (; F != L; ++F)
            {
                Tree< Tset_traits<K, Pr, A, false > >::insert(*F);
            }
        }
    };
}

#endif