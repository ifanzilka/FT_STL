/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <ifanzilka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:13:15 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/30 16:12:35 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP
# define FT_MAP

//# include <iostream>

/* Pair */
# include "../utility/utility.hpp"

/* Kernel Tree */
# include "../xtree/xtree.hpp"

/* BINARY FUNCTION */
# include "../functional/functional.hpp"

/* Свойства */
#include "tmap_traits.hpp"

namespace ft
{
    
    /* Page 579 */
    /*****************************************************/
    /*                   MAP                             */
    /*****************************************************/
    template <class K, class T, class Pr = ft::less<K>, class A = std::allocator<ft::pair<const K, T> > >
	class map: public Tree<ft::Tmap_traits<K, T, Pr, A, false> >
	{
		public:
			typedef map<K, T, Pr, A>	Myt;

			typedef Tree<Tmap_traits<K, T, Pr, A, false>  > Mybase;
			typedef K	key_type;
			typedef T	mapped_type;
			typedef T	referent_type;
			typedef Pr	key_compare;


			typedef typename Mybase::value_compare		    value_compare;
			typedef typename Mybase::allocator_type		    allocator_type;
			typedef typename Mybase::size_type			    size_type;
			typedef typename Mybase::difference_type	    difference_type;
			typedef typename Mybase::pointer			    pointer;
			typedef typename Mybase::const_pointer		    const_pointer;
			typedef typename Mybase::reference			    reference;
			typedef typename Mybase::const_reference	    const_reference;
			typedef typename Mybase::iterator			    iterator;
			typedef typename Mybase::const_iterator		    const_iterator;
			typedef typename Mybase::reverse_iterator	    reverse_iterator;
			typedef typename Mybase::const_reverse_iterator const_reverse_iterator;
			typedef typename Mybase::value_type			    value_type;


            /*****************************************************/
            /*                      Constructors                 */
            /*****************************************************/
			map(): Mybase(key_compare(), allocator_type())
			{

			}

			explicit map(const key_compare &Pred): Mybase(Pred, allocator_type())
			{

			}

			map(const key_compare &Pred, const allocator_type &Al): Mybase(Pred, Al)
			{

			}

			template <class It>
			map(It F, It L): Mybase(key_compare(), allocator_type())
			{
				for (; F != L; ++F)
					this->insert(*F);
			}

			template <class It>
			map(It F, It L, const key_compare &Pred): Mybase(Pred, allocator_type())
			{
				for (; F != L; ++F)
					this->insert(*F);
			}

			template <class It>
			map(It F, It L, const key_compare &Pred, const allocator_type &Al): Mybase(Pred, Al)
			{
				for (; F != L; ++F)
					this->insert(*F);
			}

			mapped_type &at(const key_type &Kv)
			{
				iterator P = this->find(Kv);

				if (P == this->end())
					throw std::out_of_range("key not found");
				else
					return ((*P).second);
			}

			mapped_type &at(const key_type &Kv) const
			{
				return static_cast<const mapped_type>(at(Kv));
			}
            /*****************************************************/
            /*              Overload operator                    */
            /*****************************************************/
			mapped_type &operator[](const key_type &Kv)
			{
				iterator P = this->insert(value_type(Kv, mapped_type())).first;
				return ((*P).second);
			}
	};
}

#endif