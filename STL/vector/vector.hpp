/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <bmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:15:02 by bmarilli          #+#    #+#             */
/*   Updated: 2022/03/18 18:15:03 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HEADER
# define FT_VECTOR_HEADER

/* Page 351 */

/* Подключаем для аллокатора */
# include <memory>  
# include "../memory/memory.hpp"


/* Utils (swap), (copy) (pair) */
#include "../utility/utility.hpp"

#include "../iterator/iterator.hpp"

#include "../algorithm/algorithm.hpp"


namespace ft
{
    /* Шаблонный класс vector value */
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
        
        typedef std::allocator<T> allocator_type;
        allocator_type Alval;
    
        /*  Use function : 
        **  Alval.allocate / Alval.deallocate
        **  Alval.destroy
        **  Alval.max_size
        */  

	};

    /* T - > тип данных в векторе All -> аллокатор  для выдеения памяти*/
    template<class T, class Alloc = std::allocator<T> > 
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

        /*****************************************************/
        /*                      Constructors                 */
        /*****************************************************/

        vector ();

        /* Конструктор с аллокатором */
        explicit vector (const allocator_type& Al);

        /* Конструктор с размером  */
        explicit vector (size_type N);

        /* Констурктор размер и тип */
        vector (size_type N, const T& V);

        /* Конструктор размер тип и аллокатор*/
        vector (size_type N, const T& V, const allocator_type& Al);

        /*Конустркутор с вектором */
        vector(const vector& X);

        /* Конструкторы с итераторами */
        template<class It>
        vector(It F, It L);

        template<class It>
        vector(It F, It L, const allocator_type& Al);

        /* Деструктор */
        ~vector();


        /* Переопределение оператора = */
        vector& operator = (const vector& X);

        /* Получаем аллокатор */
        allocator_type get_allocator() const;


        /*****************************************************/
        /*                      Iterators                    */
        /*****************************************************/

        iterator begin();

        const_iterator begin() const;

        iterator end();

        const_iterator end() const;

        reverse_iterator rbegin();

        const_reverse_iterator rbegin() const;

        reverse_iterator rend();

        const_reverse_iterator rend() const;

        /*****************************************************/
        /*                      Capacity                     */
        /*****************************************************/

        /* Возвращает размер вектора */
        size_type size() const;

        /* Возвращет максимальный размер аллоцированной памяти */
        size_type max_size() const;

        /* Изменение размера контейнера чтобы он содержал n элементов !!!!*/
    	void resize(size_type N, T X);

        void resize(size_type N);

        /* Возвращаемый размер выделенной памяти */
        size_type capacity() const;

        /* Проверяет, является ли вектор пустым */
        bool empty() const;

        /* Запросить изменение вместимости */
    	void reserve(size_type N);

        /******************************************************/
        /*                 Element access                    */
        /*****************************************************/
        
        /* Пеоеопределение операторов */
        const_reference operator[] (size_type N) const;

        reference operator[] (size_type N);

        /* N element , отличие от [] тем что проверяется диапозон и выкидыаетя исключение out_of_range */
        const_reference at(size_type N) const;

        /* N element , отличие от [] тем что проверяется диапозон и выкидыаетя исключение out_of_range */
        reference at(size_type N);
        
        /* Возращает первый элемент */
        reference front();

        /* Возращает первый элемент */
        const_reference front() const;

        /* Возвращает последний элемент */
        reference back();

        /* Возвращает последний элемент */
        const_reference back() const;

        /*****************************************************/
        /*                    Modifiers                      */
        /*****************************************************/
        
        /* Присваивает вектору новое содержимое, заменяя его текущее содержимое и соответствующим образом изменяя его размер. */
        template <class It>
		void assign(It F, It L);

        /* Присваивает вектору новое содержимое,  N раз элемент X */
        void assign(size_type N, const T& X);

        /* Добавить элемент в конeц */
        void push_back(const T& X);

        /* Удалить последний элемент */
        void pop_back();

        /* Вставление элемента X перед итератором P (возвращаю итератор на вставленный элемент) */
		iterator insert(iterator P, const T& X);

        /* Вставление элемента X перед итератором P  (M раз) (возвращаю итератор на вставленный элемент) */
        void insert(iterator P, size_type M, const T& X);

        template <class It>
		void insert (iterator P, It F, It L);

        /* Стирание элемента P по итератору или в промежутке */
	    iterator erase(iterator P);

        /* Стирание элемента P по итератору или в промежутке */
        iterator erase(iterator F, iterator L);

        /* Поменять местами содержимое */
        void swap(vector &X);

        /* Очищаем */
        void clear();


    protected:

        /***************/
        /*  PROTECTED  */
        /***************/
        
        /* Выделяем память и заполянем нулями и инициализируем указатели*/
        bool Allocate_zero(size_type N);

        /* Вызываю  N раз конструктор в области памяти и возвращаю указатель где вызывали Ufill */
        pointer Call_construct(pointer Q, size_type N, const T& X);

        /* Копируем зачения от First до Last (Ucopy) */
        template<class It>
		pointer ItCopy(It F, It L, pointer Q);

        /* Вспомогательные функции чтобы понять что пришло  (Базовый тип или итератор)*/
        template <class It>
        void Construct(It F, It L, Int_iterator_tag);

        template <class It>
        void Construct(It F, It L, input_iterator_tag);

        /* Вызываем деструкторы  */
        void Destroy(pointer F, pointer L);
        
        /* Вызываю деструкторы и очищаю память */
		void Clear();
        
        /* Вставление элементов из последовательности [F, L) */
        template <class It>
		void Insert(iterator P, It F, It L, Int_iterator_tag);

        template <class It>
		void Insert (iterator P, It F, It L, input_iterator_tag);

        template <class It>
		void Insert (iterator P, It F, It L, forward_iterator_tag);

        template <class It>
        void Assign(It F, It L, Int_iterator_tag);

        template <class It>
        void Assign(It F, It L, input_iterator_tag);    

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

# include "vector_rel.hpp"
# endif