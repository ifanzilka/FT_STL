/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <ifanzilka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:13:07 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/29 14:01:58 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR
# define FT_REVERSE_ITERATOR
# include "iterator.hpp"

#include <iostream>

/* При увелечении итреатора идет пошагово назад */
namespace ft
{
	// template<class RanIt>
	// class reverse_iterator : public iterator<
	// 	typename ft::iterator_traits<RanIt>::iterator_category,
	// 	typename ft::iterator_traits<RanIt>::value_type,
	// 	typename ft::iterator_traits<RanIt>::difference_type,
	// 	typename ft::iterator_traits<RanIt>::pointer,
	// 	typename ft::iterator_traits<RanIt>::reference>
	// {
	// public:
	// 	typedef reverse_iterator<RanIt> 							Myt;
	// 	typedef typename iterator_traits<RanIt>::difference_type	D;
	// 	typedef typename iterator_traits<RanIt>::pointer			Ptr;
	// 	typedef typename iterator_traits<RanIt>::reference			Ref;
	// 	typedef RanIt 												iterator_type;


	// 	/* Конструкторы */
	// 	reverse_iterator()
	// 	{

	// 	};
	// 	explicit reverse_iterator(RanIt x): current(x)
	// 	{
		
	// 	}

 
	// 	template <class U>
	// 	reverse_iterator(const reverse_iterator<U> &x): current(x.base())
	// 	{

	// 	}

	// 	RanIt base() const
	// 	{
	// 		return (current);
	// 	}
	// 	// Ref operator*() const { RanIt tmp = current; return (*--tmp); }
	// 	// Ptr operator->() const { return (&**this); }
	// 	// Myt &operator++() { --current; return (*this); }
	// 	// Myt &operator--() { ++current; return (*this); }
	// 	// Myt operator++(int) { Myt Tmp = *this; --current; return (Tmp); }
	// 	// Myt operator--(int) { Myt Tmp = *this; ++current; return (Tmp); }
	// 	// Myt operator+(D N) const { return (Myt(current - N)); }
	// 	// Myt operator-(D N) const { return (Myt(current + N)); }
	// 	// Myt &operator+=(D N) { current -= N; return (*this); }
	// 	// Myt &operator-=(D N) { current += N; return (*this); }
	// 	// Ref operator[](D N) const { return (*(*this + N)); }


	// 	/* Разыменование */
	// 	Ref operator*() const
	// 	{
	// 		RanIt tmp = current;

	// 		return (*--tmp);
	// 	}

	// 	Ptr operator->() const
	// 	{
	// 		return (&**this);
	// 	}

	// 	/* ++RevIt */
	// 	Myt& operator ++()
	// 	{
	// 		--current;
	// 		return (*this);
	// 	}

	// 	/* RevIt++ */
	// 	Myt operator ++(int)
	// 	{
	// 		Myt Tmp = *this;
	// 		--current;
	// 		return (Tmp);
	// 	}

	// 	/* --RevIt */
	// 	Myt& operator --()
	// 	{
	// 		++current;
	// 		return (*this);
	// 	}

	// 	/* RevIt-- */
	// 	Myt operator -- (int)
	// 	{
	// 		Myt Tmp = *this;
	// 		++current;
	// 		return (Tmp);
	// 	}

	// 	Myt& operator += (D N)
	// 	{
	// 		current -= N;
	// 		return (*this);
	// 	}

	// 	Myt operator + (D N) const
	// 	{
	// 		return (Myt(current - N));
	// 	}

	// 	Myt operator - (D N) const
	// 	{
	// 		return (Myt(current + N));
	// 	}

	// 	Myt& operator -= (D N)
	// 	{
	// 		current += N;
	// 		return (*this);
	// 	}

	// 	Ref operator [] (D N) const
	// 	{
	// 		return (*(*this + N));
	// 	}

	// protected:
	// 	RanIt current;

	// };

	// /* reverse_iterator TEMPLATE OPERATORS */
	// template <class RanIt, class RanIt1> inline
	// typename reverse_iterator<RanIt>::D operator - (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	// {
	// 	return (Y.base() - X.base());
	// }

	// template <class RanIt, class RanIt1> inline
	// bool operator == (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	// {
	// 	return (X.base() == Y.base());
	// }

	// template <class RanIt, class RanIt1> inline
	// bool operator != (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	// {
	// 	return (!(X ==Y));
	// }


	// template <class RanIt, class RanIt1> inline
	// bool operator < (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	// {
	// 	return (Y.base() < X.base());
	// }

	// template <class RanIt, class RanIt1> inline
	// bool operator > (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	// {
	// 	return (Y < X);
	// }

	// template <class RanIt, class RanIt1> inline
	// bool operator <= (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	// {
	// 	return (!(Y < X));
	// }

	// template <class RanIt, class RanIt1> inline
	// bool operator >= (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	// {
	// 	return (!(X < Y));
	// }

	template<class RanIt>
	class reverse_iterator : public iterator<
		typename ft::iterator_traits<RanIt>::iterator_category,
		typename ft::iterator_traits<RanIt>::value_type,
		typename ft::iterator_traits<RanIt>::difference_type,
		typename ft::iterator_traits<RanIt>::pointer,
		typename ft::iterator_traits<RanIt>::reference>
	{
		public:
			typedef reverse_iterator<RanIt> 							Myt;
			typedef typename iterator_traits<RanIt>::difference_type	D;
			typedef typename iterator_traits<RanIt>::pointer			Ptr;
			typedef typename iterator_traits<RanIt>::reference			Ref;
			typedef RanIt 												iterator_type;

			reverse_iterator() {};
			explicit reverse_iterator(RanIt x) : current(x) {}

			template <class U>
			reverse_iterator(const reverse_iterator<U> &x): current(x.base())
			{
				
			}
			
			
			
			RanIt base() const { return (current); }
			Ref operator*() const { RanIt tmp = current; return (*--tmp); }
			Ptr operator->() const { return (&**this); }
			Myt &operator++() { --current; return (*this); }
			Myt &operator--() { ++current; return (*this); }
			Myt operator++(int) { Myt Tmp = *this; --current; return (Tmp); }
			Myt operator--(int) { Myt Tmp = *this; ++current; return (Tmp); }
			Myt operator+(D N) const { return (Myt(current - N)); }
			Myt operator-(D N) const { return (Myt(current + N)); }
			Myt &operator+=(D N) { current -= N; return (*this); }
			Myt &operator-=(D N) { current += N; return (*this); }
			Ref operator[](D N) const { return (*(*this + N)); }

		protected:
			RanIt current;
	};

	template <class RanIt, class RanIt1> inline
	typename reverse_iterator<RanIt>::D operator-(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (Y.base() - X.base());
	}

	template <class RanIt, class RanIt1> inline
	bool operator==(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (X.base() == Y.base());
	}

	template <class RanIt, class RanIt1> inline
	bool operator!=(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (!(X ==Y));
	}

	template <class RanIt, class RanIt1> inline
	bool operator<(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (Y.base() < X.base());
	}

	template <class RanIt, class RanIt1> inline
	bool operator>(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (Y < X);
	}

	template <class RanIt, class RanIt1> inline
	bool operator<=(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (!(Y < X));
	}

	template <class RanIt, class RanIt1> inline
	bool operator>=(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (!(X < Y));
	}


};

#endif