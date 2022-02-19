#ifndef FT_VECTOR_OVERLOAD_OPERATOR
# define FT_VECTOR_OVERLOAD_OPERATOR

#include "vector_header.hpp"

namespace ft
{
    /* Переопределение оператора = */
    template <class T, class Alloc>
    vector<T, Alloc>& vector<T, Alloc>::operator=(const vector& X)
    {
        if (this == &X)
            ;
        else if (X.size() == 0)
        {
            Clear();
        }
        else if (X.size() <= size())
        {
            /* Если наш вектор больше чем тот откуда присваивание */
            Clear();

            pointer Q = ItCopy(X.begin(), X.end(), First);
            
            Destroy(Q, Last);
            Last = First + X.size();
        }
        else
        {
            /* Если размер нового ветора больше */
            Destroy(First, Last);
            
            _base::Alval.deallocate(First, End - First);
            
            if (Allocate_zero(X.size()))
            {
                Last = ItCopy(X.begin(), X.end(), First);
            }
        }
        return (*this);
    }
};

#endif
