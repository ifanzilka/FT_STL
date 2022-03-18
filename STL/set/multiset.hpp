/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiset.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:13:34 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:13:34 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MULTISET
# define FT_MULTISET

/* allocator */
#include <iostream>

/* Свойства */
#include "tset_traits.hpp"

/* Kernel root */
#include "../xtree/xtree.hpp"

/* Include less */
#include "../functional/functional.hpp"


namespace ft
{
    template<class K, class Pr = ft::less<K>, class A = std::allocator<K> >
    class multiset: public Tree<Tset_traits<K, Pr, A, true> >    
    {
    public:
        typedef multiset<K, Pr, A>                  Myt;
        typedef Tree<Tset_traits<K, Pr, A, true> >  Mybase;
        typedef K                                   key_type;
        typedef Pr                                  key_compare;

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

        multiset(): Mybase(key_compare(), allocator_type())
        {
        
        }

        explicit multiset(const key_compare& Pred): Mybase(Pred, allocator_type())
        {
        
        }

        multiset(const key_compare& Pred, const allocator_type &Al): Mybase(Pred, Al)
        {
        
        }


        template<class It>
        multiset(It F, It L): Mybase(key_compare(), allocator_type())
        {
            for (; F != L; ++F)
            {
                Tree< Tset_traits<K, Pr, A, false > >::insert(*F);
            }  
        }

        template<class It>
        multiset(It F, It L, const key_compare &Pred): Mybase(Pred, allocator_type())
        {
            for (; F != L; ++F)
            {
                Tree< Tset_traits<K, Pr, A, false > >::insert(*F);
            }        
        }

        template<class It>
        multiset(It F, It L, const key_compare &Pred, const allocator_type &Al): Mybase(Pred, Al)
        {
            for (; F != L; ++F)
            {
                Tree< Tset_traits<K, Pr, A, false > >::insert(*F);
            }
        }

        /*****************************************************/
        /*             Overload Function                     */
        /*****************************************************/

        iterator insert(const value_type &X)
        {
            return (Mybase::insert(X).first);
        }

        iterator insert(iterator P, const value_type &X)
        {
            return (Mybase::insert(P, X));
        } 

        template<class It>
        void insert(It F, It L)
        {
            for (; F != L ;++F)
            {
                insert(*F);
            }
        }
    };
}


#endif