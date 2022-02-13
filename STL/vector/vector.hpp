#ifndef FT_VECTOR
# define FT_VECTOR

/* Page 151 */

/* Подключаем для аллокатора */
#include <memory>  
#include "../memory/memory.hpp"


/* Utils (swap), (copy) (pair) */
#include "../utility/utility.hpp"

#include "../iterator/iterator.hpp"


namespace ft
{
    /* Шаблонный класс vector value*/
    template <class T, class A>
    class Vector_val
    {
    protected:
    
        Vector_val(A Al = A()) : Alval(Al)
        {
        
        }
        /* Грубо говоря задали аллокатор */

        //typedef typename A::template
        //   rebind<T>::other Alty;
        //Alty Alval;
        
        typedef ft::allocator<T> allocator_type;
        allocator_type Alval;
    
        /*  Use function : 
        **  Alval.allocate / Alval.deallocate
        **  Alval.destroy
        **  Alval.max_size
        */  

	};
    
    /* T - > тип данных в векторе All -> аллокатор  для выдеения памяти*/
    template<class T, class Alloc = ft::allocator<T> > 
    class vector : public Vector_val <T, Alloc> 
    {
    public:
        typedef Alloc                                       allocator_type;
        
        /* Класс от которого будем наследоваться*/       
        typedef Vector_val<T, Alloc>						_base;
        
        /* Заменяю чтобы легче было обращаться к именам*/
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::reference          reference;         // Так же как и ссылка  на Т
        typedef typename allocator_type::const_pointer      const_pointer;     // Так же как и постоянный указатель на Т
        typedef typename allocator_type::pointer            pointer;           // Так же как и указатель на Т
        typedef typename allocator_type::difference_type    difference_type;
        typedef typename allocator_type::size_type          size_type;          // беззнаковый целый тип, предсатвляет длину любой последовательности который может размещать шаблонный класс распределитель
        typedef typename allocator_type::value_type         value_type;

        typedef pointer                                     Tptr;               // T pointer											
        typedef const_pointer				                Ctptr;		      // Const Pointer	

    
        typedef random_acsees_iterator<value_type, difference_type, Tptr, reference, Tptr, reference> 
        iterator;
        
        typedef random_acsees_iterator<value_type, difference_type, Ctptr, const_reference, Tptr, reference> 
        const_iterator;
		
        typedef ft::reverse_iterator<iterator> 
        reverse_iterator;
		
        typedef ft::reverse_iterator<const_iterator>
		const_reverse_iterator;
        
        
        /* Constructors */
        vector () : _base()
        {
            Allocate_zero(0);
        }
        
        /* Конструктор с аллокатором */
        explicit vector (const allocator_type& Al): _base(Al)
        {
            Allocate_zero(0);
        }
        
        /* Конструктор с размером  */
        explicit vector (size_type N): _base()
        {
            if (Allocate_zero(N))
                Last = Call_construct(First, N, T());
        }
        
        /* Констурктор размер и тип */
        vector (size_type N, const T& V): _base()
        {
            if (Allocate_zero(N))
                Last = Call_construct(First, N, V);
        }
		
        /* Конструктор размер тип и аллокатор*/
        vector (size_type N, const T& V, const allocator_type& Al): _base(Al)
        {
            if (Allocate_zero(N))
                Last = Call_construct(First, N, V);
        }	
        
        /*Конустркутор с вектором */
        vector(const vector& X): _base(X.Alval)
        {
            if (Allocate_zero(X.size()))
                Last = ItCopy(X.begin(), X.end(), First);
        }

        /* Конструкторы с итераторами */
		template<class It>
		vector(It F, It L): _base()
        {
			Construct_EnableIf(F, L, &F);
		}
		
        template<class It>
		vector(It F, It L, const allocator_type& Al): _base(Al)
        {
			Construct_EnableIf(F, L, &F);
		}
		
        /* Деструктор */
        ~vector()
        {
			Clear();
		}
        
        /* Переопределение оператора = */
        vector& operator = (const vector& X)
        {
		    if (this == &X)
                ;
		    else if (X.size() == 0)
		    	Clear();
		    else if (X.size() <= size())
            {
                /* Если наш вектор больше чем тот откуда присваивание */
		    	pointer Q = ItCopy(X.begin(), X.end(), First);
		    	Destroy(Q, Last);
		    	Last = First + X.size();
		    }
		    else
            {
                /* Если размер нового ветора больше */
		    	Destroy(First, Last);
		    	_base::Alval.deallocate(First, End - First);
		    	if(Allocate_zero(X.size()))
		    		Last = ItCopy(X.begin(), X.end(), First);
		    }
		    return (*this);
        }


        allocator_type get_allocator() const
        {
			return (_base::Alval);
		}

        /*****************************************************/
        /*                      Iterators                    */
        /*****************************************************/

        /* мы вызваем конуструктор итератора с указателем на первый элемент */
        iterator begin()
        {
			return (iterator(First));
		}

        /* мы вызваем конуструктор итератора с указателем на первый элемент */
		const_iterator begin() const
        {
			return (const_iterator(First));
		}

        /* мы вызваем конуструктор итератора с указателем на последний элемент */
		iterator end()
        {
			return (iterator(Last));
		}

        /* мы вызваем конуструктор итератора с указателем на последний элемент */
		const_iterator end() const
        {
			return (const_iterator(Last));
		}

        /* мы вызваем конуструктор реверсивного  итератора с указателем на последний элемент */
		reverse_iterator rbegin()
        {
			return (reverse_iterator(end()));
		}

        /* мы вызваем конуструктор реверсивного  итератора с указателем на последний элемент */
		const_reverse_iterator rbegin() const
        {
			return (const_reverse_iterator(end()));
		}

        /* мы вызваем конуструктор реверсивного  итератора с указателем на первый элемент */
		reverse_iterator rend()
        {
			return (reverse_iterator(begin()));
		}
		
        /* мы вызваем конуструктор реверсивного  итератора с указателем на первый элемент */
        const_reverse_iterator rend() const
        {
			return (const_reverse_iterator(begin()));
		}

        /******************************************************/
        /*                      Capacity                     */
        /*****************************************************/
    
        /* Возвращает размер вектора */
        size_type size() const
        {
		    if (First == 0)
                return (0);
			return (Last - First);
		}

        /* Возвращет максимальный размер аллоцированной памяти */
        size_type max_size() const
        {
		    return (_base::Alval.max_size());
		}

        /* Изменение размера контейнера чтобы он содержал n элементов !!!!*/
    	void resize(size_type N, T X)
        {
            if (size() < N)
				insert(end(), N - size(), X);
			else if (N < size())
				erase(begin() + N, end());
		}

		void resize(size_type N)
        {
			resize(N, T());
		}

        /* Возвращаемый размер выделенной емкости хранилища */
        size_type capacity() const
        {
		    if (First == 0)
			    return (0);
			return (End - First);
		}

        /* Проверяет, является ли вектор пустым */
        bool empty() const
        {
		    return (size() == 0);
		}

        /* Запросить изменение вместимости */
    	void reserve(size_type N)
        {
		    if (max_size() < N) 
			    length_error(); // Исключение
		    else if (capacity() < N)
		    {
			    pointer Q = _base::Alval.allocate(N, (void *)0);
			    try
                {
				    ItCopy(begin(), end(), Q);
			    }
			    catch (...)
			    {
				    _base::Alval.deallocate(Q, N);
				    throw ;
			    }
			    if (First != 0)
                {
				    Destroy(First, Last);
				    _base::Alval.deallocate(First, End - First);
			    }
			    End = Q + N;
			    Last = Q + size();
			    First = Q;
		    }
    	}

        /******************************************************/
        /*                 Element access                    */
        /*****************************************************/

        /* Пеоеопределение операторов */
        const_reference operator[] (size_type N) const
        {   
            /* К итератору прибавили N  и разыменовали */
            return (*(begin() + N));
		}

		reference operator[] (size_type N)
        {
            /* К итератору прибавили N  и разыменовали */
            return (*(begin() + N));
		}

        /* N element , отличие от [] тем что проверяется диапозон и выкидыаетя исключение out_of_range */
        const_reference at(size_type N) const
        {
			if (size() <= N)
                out_range_error();
			return (*(begin() + N));
		}

		reference at(size_type N)
        {
            if (size() <= N)
				out_range_error(); // Исключение
			return (*(begin() + N));	
		}

        /* Возращает первый эдлемент */
        reference front()
        {
            /* Создали итератор и разыменовали */
		    return(*begin());
		}

		const_reference front() const
        {
            /* Создали итератор и разыменовали */
			return(*begin());
		}

		/* Возвращает последний элемент */
        reference back()
        {
            //std::cout << "reference back()\n";
		    return(*(end() - 1));
		}

		
        const_reference back() const
        {
            return(*(end() - 1));
		}

        /******************************************************/
        /*                    Modifiers                      */
        /*****************************************************/
        
        /***********/
        /* Assign */
        /**********/

        /* Присваивает вектору новое содержимое, заменяя его текущее содержимое и соответствующим образом изменяя его размер. */
        template <class It>
		void assign(It F, It L)
        {
            erase(begin(), end());
			Insert(begin(), F, L, Iter_cat(L));
            //Assign_EnableIf(F, L, &F);
		}
        
        void assign(size_type N, const T& X)
        {
            T Tx = X;
			erase(begin(), end());
			insert(begin(), N, Tx);
		}

        /************/
        /* push_back*/
        /***********/

        /* Добавить элемент в конeц */
        void push_back(const T& X)
        {
			insert(end(), X);
		}

        /************/
        /* pop_back*/
        /***********/

        /* Удалить последний элемент */
		void pop_back()
        {
		    erase(end() -1);
		}

        /************/
        /* Insert   */
        /***********/

        /* Вставление элемента X перед итератором P (возвращаю итератор на вставленный элемент) */
		iterator insert(iterator P, const T& X)
        {
			size_type Off;
			if (size() == 0)
				Off = 0;
			else
				Off = P - begin();
			insert(P, (size_type)1, X);
            return (begin() + Off);
		}

        /* Вставление элемента X перед итератором P  (M раз) (возвращаю итератор на вставленный элемент) */
		void insert(iterator P, size_type M, const T& X)
        {
            T Tx = X;
			size_type N = capacity();
			
			if (M == 0)
				;
			else if (max_size() - size() < M)
                length_error();
			else if (N < size() + M)
            {
                /* Если не хватает места под новые M элементов*/
				if ((max_size() - N / 2) < N)
					N = 0;
				else
					N = N + N / 2;
				if (N < size() + M)
					N = size() + M;

                pointer S = _base::Alval.allocate(N, (void *) 0);
				pointer Q;
				try
                {
				    Q = ItCopy(begin(), P, S);
                    /* Вставляю новые элементы */
					Q = Call_construct(Q, M, Tx);
                    /* Копирую остальную часть */
					ItCopy(P, end(), Q);
				}
				catch (...)
				{
				    Destroy(S, Q);
					_base::Alval.deallocate(S, N);
					throw ;
				}
				if (First != 0)
                {
                    /* Вызываю деструторы */
				    Destroy(First, Last);
                    /* Очищаю */
					_base::Alval.deallocate(First, End - First);
				}
				End = S + N;
				Last = S + size() + M;
				First = S;
			}
			else if ((size_type)(end() - P) < M)
            {
                /* Если нужно увеличить размер вектора (не переаллацируя!!! (то есть памяти хватает)) */
			    
                /* Последние элементы смещаю назад*/
                ItCopy(P, end(), P.base() + M);
				try
                {
				    Call_construct(Last, M - (end() - P), Tx);
				}
				catch (...)
                {
				    Destroy(P.base() + M, Last + M);
					throw;
				}
				Last += M;
				ft::fill(P, end() - M, Tx);
			}
			else
            {
                iterator Oend = end();
	            Last = ItCopy(Oend - M, Oend, Last);
				ft::copy_backward(P, Oend - M, Oend);
				ft::fill(P, P + M, Tx);
			}   
		}
        
        /* Вставление элементов из последовательности [F, L) */
		template <class It>
		void insert (iterator P, It F, It L)
        {
            Inset_EnableIf(P, F, L, &F);
		}

        /***********/
        /* Erase   */
        /***********/

        /* Стирание элемента P по итератору или в промежутке */
	    iterator erase(iterator P)
        {
            /* копируем элементы с позции P + 1 (грубо говоря смещаем на одну позцицию)*/
            ft::copy(P + 1, end(), P);
			Destroy(Last - 1, Last);
			--Last;
			return (P);
		}
		
       /* Стирание элемента P по итератору или в промежутке */
        iterator erase(iterator F, iterator L)
        {
        	if (F != L)
            {
				pointer S  = ft::copy(L, end(), F.base());
				Destroy(S, Last);
				Last = S;
			}
			return (F);
		}

        /**********/
        /*  Swap  */
        /**********/

        /* Поменять местами содержимое */
        void swap(vector &X)
        {
            /* Если совпали алокаторы*/
            if (_base::Alval == X.Alval)
            {
                ft::swap(First, X.First);
				ft::swap(Last, X.Last);
				ft::swap(End, X.End);
            }
            else
            {
                vector Tmp = *this;
				*this = X, X = Tmp;
            }
		}

        /***********/
        /*  Clear  */
        /***********/
        
        /* Очищаем */
        void clear()
        {
            erase(begin(), end());
		}

        /***************/
        /* PROTECTED   */
        /***************/

        protected:

        /* Вызывается этот конструктор если пришли числа */
        /* enable_if <True, T> */
        template <class It>
		void Construct_EnableIf(It F, It L, typename ft::enable_if<ft::is_integral<It>::value, It>::type * = nullptr)
        {
			size_type N = (size_type)F;
			if (Allocate_zero(N))
			    Last = Call_construct(First, N, (T)L);
		}

        /* Вызывается этот конструктор если пришли итераторы */
        /* enable_if <false, T> */
		template <class It>
        void Construct_EnableIf(It F, It L, typename ft::enable_if<!ft::is_integral<It>::value, It>::type * = nullptr)
        {
			Allocate_zero(0);
			insert(begin(), F, L);
		}

        /* Вставление элементов из последовтельности [F,L) */
        template<class It>
		void Insert(iterator P, It F, It L, input_iterator_tag)
        {
			for(; F != L; ++F, ++P)
				P = insert(P, *F);
		}

        /* Вставление элементов из последовтельности [F,L) если пришли числа */
        template <class It> 
		void Inset_EnableIf(iterator P, It F, It L, typename ft::enable_if<ft::is_integral<It>::value, It>::type * = nullptr)
        {
		    insert(P, (size_type)F, (T)L);
		}

        /* Вставление элементов из последовтельности [F,L) если пришли итераторы  */
		template <class It> 
		void Inset_EnableIf(iterator P, It F, It L, typename ft::enable_if<!ft::is_integral<It>::value, It>::type * = nullptr)
        {
		    Insert(P, F, L, Iter_cat(F));
		}

        /* Выделяем память и заполянем нулями и инициализируем указатели*/
        bool Allocate_zero(size_type N)
        {
            First = 0, Last = 0, End = 0;
            if (N == 0)
                return (false);
            else
            {
                First = _base::Alval.allocate(N, (void *)0);
                Last = First;
                End = First + N;
                return (true);
            }
        }

        /* Вызываю деструкторы и очищаю память */
		void Clear()
        {
            if (First != 0)
            {
                Destroy(First, Last);
                /* Очищаем область */
                _base::Alval.deallocate(First, End - First);
            }
            First = 0, Last = 0, End = 0;
        }

        /* Вызываем деструкторы  */
        void Destroy(pointer F, pointer L)
        {
            for(; F != L; ++F)
                _base::Alval.destroy(F);
        }


        /* Копируем зачения от First до Last (Ucopy) */
        template<class It>
		pointer ItCopy(It F, It L, pointer Q)
        {
			pointer Qs = Q;
			try
            {
				for(; F != L; ++Q, ++F)
					_base::Alval.construct(Q, *F);
			}
			catch (...)
			{
				Destroy(Qs, Q);
				throw;
			}
			return (Q);
		}

        /* Вызываю  N раз конструктор в области памяти и возвращаю указатель где вызывали Ufill*/
    	pointer Call_construct(pointer Q, size_type N, const T& X)
        {
            pointer Qs = Q;
            try
            {
                for(; 0 < N; --N, ++Q)
                    _base::Alval.construct(Q, X);
            }
            catch (...)
            {
                Destroy(Qs, Q);
                throw;
            }
            return (Q);
        }

        /*****************************************************/
        /*                    Utils                          */
        /*****************************************************/

        /* lenght error Xlen*/
        void length_error() const
        {
            throw "vector<T> too long";
		    //throw std::length_error("vector<T> too long");
		}
		
        /*  Out of range  Xran*/
        void out_range_error() const
        {
            throw "vector<T> subscript";
		    //throw std::length_error("vector<T> subscript");
		}

        /* Указатель на T .На начало , на полседний элемент , на конец */
        pointer First, Last, End;

    };    

    /*****************************************************/
    /*             Overload operators                    */
    /*****************************************************/

    template<class T, class allocator_type> inline
	bool operator == (const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
    {
	    return (X.size() == Y.size() && ft::equal(X.begin(), X.end(), Y.begin()));
	}

	template<class T, class allocator_type> inline
	bool operator != (const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
    {
	    return (!(X == Y));
	}

	template<class T, class allocator_type> inline
	bool operator < (const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
    {
		return (ft::lexicographical_compare(X.begin(), X.end(), Y.begin(), Y.end()));
	}
	
    template<class T, class allocator_type> inline
	bool operator > (const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
    {
		return (Y < X);
	}
	
    template<class T, class allocator_type> inline
	bool operator >= (const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
    {
		return (!(X < Y));
	}
	
    template<class T, class allocator_type> inline
	bool operator <= (const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
    {
		return (!(Y < X));
	}
	
	template<class T, class allocator_type> inline
	void swap (vector<T, allocator_type>& X, vector<T, allocator_type>& Y)
    {
		X.swap(Y);
	}
}

#endif