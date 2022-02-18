#ifndef FT_VECTOR_HEADER
# define FT_VECTOR_HEADER

/* Page 151 */

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

    };
}

# include "vector_rel.hpp"
# endif