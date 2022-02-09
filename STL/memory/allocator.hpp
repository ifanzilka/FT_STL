#ifndef FT_ALLOCATOR
# define FT_ALLOCATOR

# include "../utility/utility.hpp"
# include <new>

#ifndef FARQ
# define FARQ
# define PDFT	ptrdiff_t
# define SIZT	size_t

#endif /* _FARQ */


namespace ft
{
	// template <class T> inline
	// T FARQ *Allocate(SIZT N, T FARQ *)
	// {
	// 	return ((T FARQ *) operator new(N * sizeof(T))));
	// }

	/* Шаблонная функция Allocate */
	template <class T> inline    
	/* Выделяю память */
	T*  Allocate(SIZT N, T*)
	{
		return ((T*)operator new (N * sizeof(T)));
	}

    /* Шаблонная функция  Construct */
    template <class T1,class T2> inline
    void    Construct(T1 *P, const T2 & V)
    {
        new ((void *)P) T1(V);
    }

    /* Шаблонная функция Destroy */
    template <class T> inline
    void Destroy(T *P)
    {
        P->~T();
    }

    template<class T>
    class allocator
    {
    public:
        typedef SIZT        size_type;
        typedef PDFT        difference_type;
        typedef T*          pointer;
        typedef const T*    const_pointer;
        typedef T&          reference;
        typedef const T&    const_reference;
        typedef T           value_type;

        /* 
        ** Этот шаблонны класс определяет тип other 
        ** Его предназначение обеспечить доступность 
        ** allocator<U> имея обьект типа allocator<T>
        */
        template <class U>
        struct rebind
        {
            typedef ft::allocator<U> other;
        };

        pointer address(reference X) const
        {
            return (&X);
        }

        const_pointer address(const_reference X) const
        {
            return (&X); 
        }

        /* Конструкторы  */
        allocator()
        {
        }

        /* Конструктор c аллокатором  */
        allocator(const allocator <T> &)
        {

        }

        /* Создаем конструктор на основе другого типа */
        template <class U>
        allocator(const allocator <U> &)
        {
            
        }

        template <class U>
        allocator<T> & operator=(const allocator <U> &)
        {
            return (*this);
        }

        template <class U>
        pointer allocate(size_type N, const U )
        {
            return (Allocate(N, (pointer)0));    
        }

        
        pointer allocate(size_type N)
        {
            return (Allocate(N, (pointer)0));    
        }

        void deallocate(pointer P, size_type)
        {
            operator delete(P);
        }

        void construct(pointer P, const T& V)
        {
            Construct(P, V);
        }

        void destroy(pointer P)
        {
            Destroy(P);
        }

        SIZT max_size() const
        {
            SIZT N = (SIZT)(-1) / sizeof(T);
            if (N > 0)
            {
                return (N);
            }
            else
            {
                return (1);
            }
        }
  
    };

};

#endif