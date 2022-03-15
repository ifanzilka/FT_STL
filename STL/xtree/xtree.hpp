#ifndef FT_XTREE
# define FT_XTREE


#include "../utility/utility.hpp"

/* Итераторы */
#include "../iterator/iterator.hpp"

/* lexicographical compare  */
#include "../algorithm/algorithm.hpp"



/* Page 484 */
/* Page 517 */

/* Красно Черные Деревья
** 1) Корень всегда -> черный
** 2) конечные узлы тоже -> черные
** 3) Дочерние от красного -> черные
** 4) Все пуьт до NULL умеет одинаковое кол во черных узлов
*/ 


namespace ft
{
    /*
    **    template <class Tr>
    **    class Tree;
    **      Параметры для дерева 
    **    struct tree_traits
    **    {
    **        typedef T1  key_type;            Ключ в каждом элементе
    **        typedef T2  value_type;          Тип значения в каждом элементе
    **        typedef T3  allocator_type;      Аллокатор 
    **    };
    */

    template <class Tree_traits>
    class tree_iterator;

    template <class Tree_traits>
    class const_tree_iterator;

    /* Page 516 */
    template <class Tree_traits>
    class Tree_nod : public Tree_traits //Наследуем различные Параметры 
    {
    protected:
        typedef typename Tree_traits::allocator_type    allocator_type;
		typedef typename Tree_traits::key_compare       key_compare;    /* Тип для сравнивания двух Node (это класс вызваем оператор ())*/
		typedef typename Tree_traits::key_type	        key_type;       /* Тип ключ */
		typedef typename Tree_traits::value_compare	    value_compare;  /* Тип для сравнивания по ключу */
		typedef typename Tree_traits::value_type		value_type;     /* Тип значения */

        /* Берем аллокатор из tree_traits, из этого аллокатора делаем аллокатор на void и делаем ссылку */
        typedef typename allocator_type::
            template rebind<void>::other::pointer	    Tree_ptr;
        
        typedef typename allocator_type::
            template rebind<void>::other::pointer       Genptr;
        
        struct Node;
        friend struct Node;
        struct Node
        {
            /* Указатель на родителя, на левую часть, и на правую */
            Tree_ptr    Left;
            Tree_ptr    Parent;
            Tree_ptr    Right;

            value_type  Value;
            
            /* Цвет ноды (Черное-Красное)*/
            char Color;

            /* Говорит нода NULL или нет*/
            char Isnil;
        };

        /* Конструктор */
        Tree_nod(const key_compare& Parg, allocator_type Al): Tree_traits(Parg),  Alnod(Al)
        {

        }
        
        /* Делаеи тип  */
        typename allocator_type::
            template rebind<Node>::other                Alnod;
    };
    
    template <class Tree_traits>
	class Tree_ptr : public Tree_nod<Tree_traits>
    {
    protected:
		typedef typename Tree_nod<Tree_traits>::Node    Node;
		typedef typename Tree_traits::allocator_type    allocator_type;
		typedef typename Tree_traits::key_compare		key_compare;
		

        typedef typename allocator_type::
            template rebind<Node>::other::pointer	    Nodeptr;
        
        typedef typename allocator_type::
            template rebind<Node>::other::const_pointer	const_nodeptr;

        /* Конуструктор */
		Tree_ptr(const key_compare& Parg, allocator_type Al):Tree_nod<Tree_traits>(Parg, Al)
        {

        }
        
        typename allocator_type
				::template rebind<Nodeptr>::other Alptr;
	};

    /* Класс для хранения обьекта распределителя */
    template <class Tree_traits>
	class Tree_val : public Tree_ptr<Tree_traits>
    {
	protected:
		typedef typename Tree_traits::allocator_type    allocator_type;
		typedef typename Tree_traits::key_compare       key_compare;

        /* Конуструктор */
        Tree_val(const key_compare& Parg, allocator_type Al): Tree_ptr<Tree_traits>(Parg, Al), Alval(Al)
        {

        }
		
        allocator_type Alval;
	};

    template <class Tree_traits>
    class Tree : public Tree_val<Tree_traits>
    {
    public:
        typedef Tree<Tree_traits>                               Myt;
        typedef Tree_val<Tree_traits>                           Mybase;

        typedef typename Tree_traits::key_type				    key_type;
		typedef typename Tree_traits::key_compare			    key_compare;
		typedef typename Tree_traits::value_compare		        value_compare;
        typedef typename Tree_traits::value_type			    value_type;
		
        typedef typename Tree_traits::allocator_type		    allocator_type;
        typedef typename allocator_type::size_type              size_type;
        typedef typename allocator_type::difference_type        difference_type;
        
	protected:
        typedef typename Tree_nod<Tree_traits>::Genptr	    Genptr;
        typedef typename Tree_nod<Tree_traits>::Node		Node;
        
        enum Redbl 
        {
            Red, 
            Black
        };
        
        typedef typename allocator_type::template
                rebind<Node>::other::pointer				Nodeptr;
        
        typedef typename allocator_type::template
                rebind<Nodeptr>::other::reference			Nodepref;
        
        typedef typename allocator_type::template
                rebind<key_type>::other::const_reference	Keyref;
        
        typedef typename allocator_type::template
                rebind<char>::other::reference				Charref;
        
        typedef typename allocator_type::template
                rebind<value_type>::other::reference		Vref;

        /* Возвращает цвет ноды */
        static Charref	Color(Nodeptr P);
        
        static Charref	Isnil(Nodeptr P);
        
        static Keyref	Key(Nodeptr P);

        /* Возвращает левую ноду */
        static Nodepref Left(Nodeptr P);

        /* Возвращает родительскую ноду */
        static Nodepref Parent(Nodeptr P);

        /* Возвращает правую ноду */
        static Nodepref Right(Nodeptr P);

        static Vref		Value(Nodeptr P);

    public:
        typedef typename allocator_type::difference_type	Dift;
        
        typedef typename allocator_type::template
				rebind<value_type>::other::pointer			    Tptr;

        typedef typename allocator_type::template
            rebind<value_type>::other::const_pointer		Ctptr;
        typedef typename allocator_type::template
            rebind<value_type>::other::reference			Reft;
        
        typedef Tptr										pointer;
        typedef Ctptr										const_pointer;
        typedef Reft										reference;
        
        typedef typename allocator_type::template
            rebind<value_type>::other::const_reference		const_reference;


        /* ITERATORS */
		typedef ft::tree_iterator<Tree_traits>          iterator;
        friend class tree_iterator<Tree_traits>;

        /* CONST ITERATORS */
        typedef ft::const_tree_iterator<Tree_traits>    const_iterator;
        friend class const_tree_iterator<Tree_traits>;

        /* Reverse Iterator */
        typedef ft::reverse_iterator<iterator>              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;


        /* PAIR */
        typedef ft::pair<iterator, bool>                    Pairib;
        typedef ft::pair<iterator, iterator>                Pairii;
        typedef ft::pair<const_iterator, const_iterator>    Paircc;


    public:
        /*****************************************************/
        /*                      Constructors                 */
        /*****************************************************/

        /* explict запрещает приведение */
        explicit Tree(const key_compare &Parg, const allocator_type& Al);

        Tree(const value_type *F, const value_type *L, const key_compare& Parg, const allocator_type &Al);

        Tree(const Myt & x);
        
        /* Overload operator ()=) */
        Myt&operator=(const Myt & x);

        ~Tree();

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
        /*             Function                              */
        /*****************************************************/
        
        /* Количество элементов */
        size_type size() const;

        /* максимальное кол-во элементов  */ 
        size_type max_size() const;

        /* True если size = 0 */
        bool empty() const;

        /* Аллокатор */
        allocator_type get_allocator() const;

        key_compare key_comp() const;

        value_compare value_comp() const;


        /*****************************************************/
        /*              Modifers                             */
        /*****************************************************/


        Pairib      insert(const value_type & V);
        iterator    insert(iterator P, const value_type &V);

        template<class It>
        void insert(It F, It L);


        iterator    erase(iterator P);
        iterator    erase(iterator F, iterator L);
        size_type   erase(const key_type& X);
        void        erase(const key_type *F, const key_type *L);

        void clear();

        iterator        find(const key_type & Kv);
        const_iterator  find(const key_type & Kv) const;

        size_type       count(const key_type & Kv) const;
        
        /* Для обнаружение первого элемента в поледовательности который не упорядочен перед key*/
        iterator        lower_bound(const key_type & Kv);
        const_iterator  lower_bound(const key_type & Kv) const;

        /* Для обнаружение первого элемента в поледовательности который  упорядочен после key*/
        iterator        upper_bound(const key_type & key);
        const_iterator  upper_bound(const key_type & key) const;


        Pairii equal_range(const key_type & Kv);
        Paircc equal_range(const key_type & Kv) const;

        void swap(Myt &X);

    protected:

        /* Выделяет память под одну ноду и инициализируем */
        void Init();

        void Copy(const Myt &X);

        Nodeptr Copy(Nodeptr X, Nodeptr P);

        void Erase(Nodeptr X);

        iterator Insert(bool Addleft, Nodeptr Y, const value_type &v);

        /* от Ноды возвращаю левую ветвь */
        Nodeptr& Lmost();

        /* от Ноды возвращаю левую ветвь */
        Nodeptr& Lmost() const;

        /* от Ноды возвращаю правую ветвь */
        Nodeptr& Rmost();

        /* от Ноды возвращаю правую ветвь */
        Nodeptr& Rmost() const;

        /* от Ноды возвращаю родительскую ветвь */
        Nodeptr& Root();
        
        /* от Ноды возвращаю родительскую ветвь */
        Nodeptr& Root() const;


        void Lrotate(Nodeptr X);

        void Rrotate(Nodeptr X);

        static Nodeptr Max(Nodeptr P);

        static Nodeptr Min(Nodeptr P);
        
        //
        Nodeptr Lbound(const key_type &Kv) const;
        //
        Nodeptr Ubound(const key_type& Kv) const;

        /* Выделяет память под новую ноду, задает родителя и цвет ноде */
        Nodeptr Buynode(Nodeptr Parg, char Carg);

        /* По указателю вызываю конструктор и кладу значение */
        void Consval(Tptr P, const value_type& V);
        
        /* Вызываю деструктор по указателю */
        void Destval(Tptr P);

        /* Вызываю деструткоры у ноды и особождаю память */
        void Freenode(Nodeptr S);

        /* */
        Nodeptr     Head;
        /* Размер дерева*/
        size_type   Size;
    };
    template <class Tree_traits> inline
	void swap(Tree<Tree_traits> &X, Tree<Tree_traits> &Y)
	{
		X.swap(Y);
	}

    /*****************************************************/
    /*       OVERLOAD OPERTORS                          */
    /*****************************************************/

    /* X == Y */
	template <class Tr> inline
	bool operator==(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (X.size() == Y.size() && ft::equal(X.begin(), X.end(), Y.begin()));
	}

    /* X != Y*/
    template <class Tr> inline
	bool operator!=(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (!(X == Y));
	}

    /* X < Y */
    template <class Tr> inline
	bool operator<(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (ft::lexicographical_compare(X.begin(), X.end(), Y.begin(), Y.end(), X.value_comp()));
	}

    /* X > Y */
    template <class Tr> inline
	bool operator>(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (Y < X);
	}

    /* X <= Y */
    template <class Tr> inline
	bool operator<=(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (!(Y < X));
	}

    /* X >= Y */
	template <class Tr> inline
	bool operator>=(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (!(X < Y));
	}
}
#include "xtree_iterator.hpp"
#include "xtree_const_iterator.hpp"
#include "xtree_constructor.hpp"
#include "xtree_get_allocator.hpp"
#include "xtree_function.hpp"
#include "xtree_init.hpp"
#include "xtree_buynode.hpp"
#include "xtree_Nodeptr_fun.hpp"
#include "xtree_modifers.hpp"
#include "xtree_protected.hpp"
#include "xtree_iterator_fun.hpp"
#include "xtree_rotate.hpp"

#endif