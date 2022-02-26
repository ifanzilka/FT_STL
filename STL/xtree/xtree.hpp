#ifndef FT_XTREE
# define FT_XTREE

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
    class Tree_nod : public Tr //Наследуем различные Параметры 
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
    
        typedef typename allocator_type::template       rebind<Node>::other::pointer	Nodeptr;

        /* Constructor */
        Tree(const key_compare &Parg, allocator_type Al);
		
        /* Constructor */
		template <class It>
		Tree(const key_compare & Parg, allocator_type Al, It F, It L);

        /* Destructor */
		~xtree();

    protected:

    };
}

#endif