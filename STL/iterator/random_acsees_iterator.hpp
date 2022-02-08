#ifndef FT_RANDOM_ACSEES_ITERATOR
# define FT_RANDOM_ACSEES_ITERATOR

namespace ft
{
		// TEMPLATE CLASS random_acsees_iterator (Ptrit)

	template <class T, class D, class Pt, class Rt, class Pt2, class Rt2>
	class random_acsees_iterator : public iterator<random_access_iterator_tag, T, D, Pt, Rt> 
	{
	public:
		typedef random_acsees_iterator<T, D, Pt, Rt, Pt2, Rt2> Myt;
		
		random_acsees_iterator() 
		{

		};
		
		explicit random_acsees_iterator(Pt P): current (P) 
		{

		}

		random_acsees_iterator(const random_acsees_iterator<T, D, Pt, Rt, Pt2, Rt2> &X): current (X.base()) 
		{

		}
		
		template <class _T, class _D, class _Pt, class _Rt, class _Pt2, class _Rt2>
		random_acsees_iterator(const random_acsees_iterator<_T, _D, _Pt, _Rt, _Pt2, _Rt2> &X): current (X.base()) 
		{

		}

		Pt base() const
		{
			return (current);
		}
		
		Rt operator * () const
		{
			return (*current);
		}
		
		Pt operator -> () const
		{
			return (&**this);
		}
		
		Myt& operator++ ()
		{
			++current;
			return (*this);
		}
		
		Myt operator ++ (int)
		{
			Myt Tmp = *this;
			
			++current;
			return (Tmp);
		}
		
		Myt& operator-- ()
		{
			--current;
			return (*this);
		}
		
		Myt operator -- (int)
		{
			Myt Tmp = *this;
			--current;
			return (Tmp);
		}
		
		bool operator == (int Y) const
		{
			return (current == (Pt)Y);
		}
		
		bool operator == (const Myt& Y) const
		{
			return (current == Y.current);
		}
		
		bool operator != (const Myt& Y) const
		{
			return (!(*this == Y));
		}
		
		Myt& operator += (D N)
		{ 
			current += N;
			return (*this);
		}
		
		Myt operator + (D N) const
		{
			return (Myt(current + N));
		}
		
		Myt& operator -= (D N)
		{ 
			current -= N;
			return (*this);
		}
		
		Myt operator - (D N) const
		{
			return (Myt(current - N));
		}
		
		Rt operator [] (D N) const
		{
			return (*(*this + N));
		}
		
		bool operator < (const Myt& Y) const
		{
			return (current < Y.current);
		}
		
		bool operator > (const Myt& Y) const
		{
			return (Y < *this);
		}
		
		bool operator <= (const Myt& Y) const
		{
			return (!(Y < *this));
		}
		
		bool operator >= (const Myt& Y) const
		{
			return (!(*this < Y));
		}
		
		D operator - (const Myt& Y)
		{
			return (current - Y.current);
		}
	protected:
		Pt current;
	};
	
	template <class T, class D, class Pt, class Rt, class Pt2, class Rt2, class D0> inline
	random_acsees_iterator <T, D, Pt, Rt, Pt2, Rt2> operator + (D0 N, const random_acsees_iterator<T, D, Pt, Rt, Pt2, Rt2>& Y)
	{ 
		return (Y + static_cast<D>(N));
	}

};

#endif