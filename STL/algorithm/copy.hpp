#ifndef FT_COPY
# define FT_COPY

namespace ft
{
	/* Копируем в итератор X */
	template <class InIt, class OutIt> inline
	OutIt copy(InIt F, InIt L, OutIt X)
	{
		for (; F != L; ++X, ++F)
		{
			*X = *F;
		}
		return (X);
	}

	template <class BidIt1, class BidIt2> inline
	BidIt2 copy_backward (BidIt1 F, BidIt1 L, BidIt2 X)
	{
		while (F != L)
		{
			*--X = *--L;
		}
		return (X);
	}

};

#endif