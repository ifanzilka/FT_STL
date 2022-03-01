#ifndef FT_XTREE
# define FT_XTREE


/* Итераторы */
#include "../STL/iterator/iterator.hpp"

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

    /* Page 516 */
    template <class Tree_traits>
    class Tree_nod : public Tree_traits //Наследуем различные Параметры 
    {
    protected:
        typedef typename Tree_traits::allocator_type    allocator_type;
		typedef typename Tree_traits::key_compare       key_compare;    /* Тип для сравнивания двух Node */
		typedef typename Tree_traits::key_type	        key_type;       /* Тип ключ */
		typedef typename Tree_traits::value_compare	    value_compare;  /* Тип для сравнивания по ключу */
		typedef typename Tree_traits::value_type		value_type;     /* Тип значения */

        /* Берем аллокатор из tree_traits, из этого аллокатора делаем аллокатор на void и делаем ссылку */
        typedef typename allocator_type::
            template rebind<void>::other::pointer	    Tree_ptr;
        

        struct Node;
        friend struct Node;
        struct Node
        {
            /* Указатель на родителя, на левую часть, и на правую */
            Tree_ptr    Left;
            Tree_ptr    Parent;
            Tree_ptr    Right;

            value_type  Value;
            char Color, Isnil;
        };

        /* Конуструктор */
        Tree_nod(const key_compare& Parg, allocator_type Al): Tree_traits(Parg),  Alnode(Al)
        {

        }
        
        /* Делаеи тип  */
        typename allocator_type::
            template rebind<Node>::other                Alnode;
    };
    
    template <class Tree_traits>
	class Tree_ptr : public Tree_nod<Tree_traits>
    {
    protected:
		typedef typename Tree_nod<Tree_traits>::Node    Node;
		typedef typename Tree_traits::allocator_type    allocator_type;
		typedef typename Tree_traits::key_compare		key_compare;
		

        typedef typename allocator_type::
            template rebind<Node>::other::pointer	    nodeptr;
        
        typedef typename allocator_type::
            template rebind<Node>::other::const_pointer	const_nodeptr;

        /* Конуструктор */
		Tree_ptr(const key_compare& Parg, allocator_type Al):Tree_nod<Tree_traits>(Parg, Al)
        {

        }
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

        typedef typename allocator_type::
            template       rebind<Node>::other::pointer                 Nodeptr;
        
        typedef typename allocator_type::
            template       rebind<value_type>::other::pointer	        Tptr;
        
        typedef typename allocator_type::
            template       rebind<value_type>::other::const_pointer	    Cptr;
        
        typedef typename allocator_type::
            template       rebind<value_type>::other::reference         Reft;
        

	protected:
			
        typedef typename Tree_nod<Tr>::Genptr	            Genptr;
		typedef typename Tree_nod<Tr>::Node                 Node;

        enum Redbl 
        {
            Red,
            Black
        };

        typedef typename allocator_type::template
					rebind<Node>::other::pointer		    Nodeptr;
        typedef typename allocator_type::template
                rebind<Nodeptr>::other::reference			Nodepref;
        typedef typename allocator_type::template
                rebind<key_type>::other::const_reference	Keyref;
        typedef typename allocator_type::template
                rebind<char>::other::reference				Charref;
        typedef typename allocator_type::template
                rebind<value_type>::other::reference		Vref;
    

        static Charref	Color(Nodeptr P)	{ return ((Charref)(*P).Color); }
        static Charref	Isnil(Nodeptr P) 	{ return ((Charref)(*P).Isnil); }
        static Keyref	Key(Nodeptr P)		{ return (Keyref()(Value(P))); }
        static Nodepref Left(Nodeptr P)		{ return ((Nodepref)(*P).Left); }
        static Nodepref Parent(Nodeptr P)	{ return ((Nodepref)(*P).Parent); }
        static Nodepref Right(Nodeptr P)	{ return ((Nodepref)(*P).Right); }
        static Vref		Value(Nodeptr P)	{ return ((Vref)(*P).Value); }    

    public:
        typedef Tptr pointer;
        typedef Cptr const_pointer;
        typedef Reft reference;

        typedef typename allocator_type::
            template rebind<value_type>::other::const_reference         const_reference;

        /* Class Iterator */
        class iterator;
        friend class iterator;
        class iterator: public Bidit<value_type, difference_type, Tptr, Reft>
        {   
            /* TO DO*/
        };

        

    };
}

#endif