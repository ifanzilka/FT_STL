#ifndef FT_SWAP
# define FT_SWAP

namespace ft
{
	template <class T> inline
	void swap(T& X, T& Y)
	{
		T Tmp = X;
		X = Y, Y = Tmp;
	}
}

#endif