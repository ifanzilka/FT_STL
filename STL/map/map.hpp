#ifndef FT_MAP
#define FT_MAP

#include <iostream>

#include "../utility/utility.hpp"

/* Kernel Tree */
#include "../xtree/xtree.hpp"

namespace ft
{
    /*****************************************************/
    /*                  TMAP_TRAITS                       */
    /*****************************************************/

    template <class K, class T, class Pr, class Ax, bool Mfl>
    class Tmap_traits
    {
    public:
        typedef K                               key_type;
        typedef ft::pair<const K, T>            value_type;
        typedef Pr                              key_comapre;
        typedef typename Ax::
            template rebind<value_type>::other allocator_type;

        enum
        {
            Multi = Mfl;
        };

        Tmap_traits() : comp()
        {

        }
        
        Tmap_traits(Pr Parg) : comp(Parg)
        {

        }

        class value_compare: public std::binary_function<value_type, value_type, bool>
        {
        friend class Tmap_traits<K, T, Pr, Ax, Mfl>;
        
        public:

            bool operator() (const value_type &X, cosnt value_type &Y) const
            {   
                return (comp(X.fires, Y.first));
            }

        protected:
            key_compare comp;
        };

        struct Kfn
        {
            const K& operator()(const value_type &X) const
            {
                return (X.first);
            }
        };

        Pr comp;

    };



    /*****************************************************/
    /*                   MAP                             */
    /*****************************************************/

    template<class K, class T, class Pr = std::less<K>, class A = std::allocator<K> >
    class map : public Tree<Tmap_traits<K, T, Pr, A, false> >
    {
    public:
        typedef map<K, T, Pr, A>                        Myt;

        typedef Tree<Tmap_traits<K, T, Pr, A, false> >  Mybase;

        typedef K                       key_type;
        typedef T                       mapped_type;
        typedef T                       referent_type;
        typedef Pr                      key_compare;
        //typedef A                       allocator_type;


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

        map(): Mybase(key_compare(), allocator_type())
        {

        }

        explicit map(const key_compare & Pred): Mybase(Pred, allocator_type())
        {

        }

        template<class It>
        map(It F, It L): Mybase(key_compare(), allocator_type())
        {
            //
        }

        template<class It>
        map(It F, It L, const key_compare & Pred): Mybase(Pred, allocator_type())
        {
            //
        }

        template<class It>
        map(It F, It L, const key_compare & Pred, const allocator_type & al): Mybase(Pred, al)
        {
            //
        }

        /*****************************************************/
        /*              Overload operator                    */
        /*****************************************************/
        mapped_type& operator[] (const key_type& Kv)
        {
            iterator P = insert(value_type(Kv, mapped_type())).first;

            return ((*P).second);
        }
    };
}

#endif