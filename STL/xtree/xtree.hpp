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
    // template <class Tr>
    // class Tree;
    // /* Параметры для дерева */
    // struct tree_traits
    // {
    //     typedef T1  key_type;           /* Ключ в каждом элементе*/
    //     typedef T2  value_type;         /* Тип значения в каждом элементе*/
    //     typedef T3  allocator_type;     /* Аллокатор */
    // };

    template <class Tree_traits>
    class Tree_nod : public Tree_traits //Наследуем различные Параметры 
    {
    protected:
        typedef typename Tree_traits::allocator_type    allocator_type;
		typedef typename Tree_traits::key_compare       key_compare;
		typedef typename Tree_traits::key_type	        key_type;
		typedef typename Tree_traits::value_compare	    value_compare;
		typedef typename Tree_traits::value_type		value_type;

        /* Заменяем аллокатор чтобы было удобней рабоать */
        typedef typename allocator_type::template       rebind<void>::other::pointer	Tree_ptr;
        
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
        
        /* Заменяем аллокатор чтобы было удобней рабоать */
        typename allocator_type::template   rebind<Node>::other Alnode;
    };
    
    template <class Tree_traits>
	class Tree_ptr : public Tree_nod<Tree_traits>
    {
    protected:
		typedef typename Tree_nod<Tree_traits>::Node    Node;
		typedef typename Tree_traits::allocator_type    allocator_type;
		typedef typename Tree_traits::key_compare		key_compare;
		
        typedef typename allocator_type::template       rebind<Node>::other::pointer	    nodeptr;
        typedef typename allocator_type::template       rebind<Node>::other::const_pointer	const_nodeptr;

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

        typedef typename allocator_type::template       rebind<Node>::other::pointer                Nodeptr;
        typedef typename allocator_type::template       rebind<value_type>::other::pointer	        Tptr;
        typedef typename allocator_type::template       rebind<value_type>::other::const_pointer	Cptr;
        typedef typename allocator_type::template       rebind<value_type>::other::reference        Reft;
        
        typedef Tptr pointer;
        typedef Cptr const_pointer;
        typedef Reft reference;
        typedef typename allocator_type::template       rebind::<value_type>::other::const_reference;

        /* Итерараторы */
        typedef tree_const_iterator<Tree_traits>        const_iterator;
		typedef tree_iterator<Tree_traits>	            iterator;

		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;



        /* Constructor */
        Tree(const key_compare &Parg, allocator_type Al);
		
        /* Constructor with iterator First and Last */
		template <class It>
		Tree(const key_compare & Parg, allocator_type Al, It F, It L);

        /* Destructor */
		~xtree();

    protected:
        typedef typename Tree_nod <Tree_traits>::Node		Node;


    };
}

#endif