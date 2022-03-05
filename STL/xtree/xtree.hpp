#ifndef FT_XTREE
# define FT_XTREE


#include "../utility/utility.hpp"

/* Итераторы */
#include "../iterator/iterator.hpp"

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
            char Color, Isnil;
        };

        // Tree_nod()
        // {

        // }

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


        // Tree_ptr()
        // {

        // }

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
        
        // Tree_val()
        // {

        // }


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

        static Charref	Color(Nodeptr P)	{ return ((Charref)(*P).Color); }
        static Charref	Isnil(Nodeptr P) 	{ return ((Charref)(*P).Isnil); }
        static Keyref	Key(Nodeptr P)		{ return (Keyref()(Value(P))); }
        static Nodepref Left(Nodeptr P)		{ return ((Nodepref)(*P).Left); }
        static Nodepref Parent(Nodeptr P)	{ return ((Nodepref)(*P).Parent); }
        static Nodepref Right(Nodeptr P)	{ return ((Nodepref)(*P).Right); }
        static Vref		Value(Nodeptr P)	{ return ((Vref)(*P).Value); }  

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

        /* Class Iterator */
        class iterator;
        friend class iterator;
        class iterator: public Bidit<value_type, difference_type, Tptr, Reft>
        {   
            typedef Bidit<value_type, difference_type, Tptr, Reft>  Mybase;
            typedef typename Mybase::iterator_category              iterator_category;
            typedef typename Mybase::value_type                     value_type;
            typedef typename Mybase::difference_type                difference_type;
            typedef typename Mybase::pointer                        pointer;
            typedef typename Mybase::reference                      reference;


            /* Constructor */
            iterator(): Ptr(0){};

            /* Constructor */
            iterator(Nodeptr P): Ptr(P) {};


            /* Overload operator */
            reference operator*() const 
            {
                return (Value(Ptr));
            }
            
            Tptr operator->() const {return (&**this);}

            iterator& operator++()
            {
                Inc();
                return(*this);
            }

            iterator operator++(int)
            {
                iterator Tmp = *this;
                
                ++*this;
                return (Tmp);
            }

            iterator& operator-()
            {
                Dec();
                return (*this);
            }

            iterator operator--(int)
            {
                iterator Tmp = *this;
                
                --*this;
                return (Tmp);
            }


            bool operator==(const iterator X) const {return (Ptr == X.Ptr);}

            bool operator!=(const iterator X) const {!(*this == X);}

            void Dec()
            {
                if (Isnil(Ptr))
                    ;
                else if (!Isnil(Left(Ptr)))
                {   
                    Ptr = Max(Left(Ptr));
                }
                else
                {
                    Nodeptr P;

                    while (!Isnil(P == Parent(Ptr)) && Ptr == Left(P))
                    {
                        Ptr = P;
                    }
                    if (!Isnil(P))
                    {
                        Ptr = P;
                    }
                }
            }

            void Inc()
            {
                if (Isnil(Ptr))
                    ;
                else if (!Isnil(Right(Ptr)))
                {   
                    Ptr = Min(Right(Ptr));
                }
                else
                {
                    Nodeptr P;

                    while (!Isnil(P == Parent(Ptr)) && Ptr == Right(P))
                    {
                        Ptr = P;
                    }
                }
            }

            Nodeptr Mynode() const {return (Ptr);}

        protected:
            Nodeptr Ptr;    
        };

        /* Class const Iterator */
        class const_iterator;
        friend class const_iterator;
        class const_iterator: public Bidit<value_type, difference_type, Ctptr, const_reference>
        {   
            typedef Bidit<value_type, difference_type, Ctptr, const_reference>  Mybase;
            typedef typename Mybase::iterator_category                          iterator_category;
            typedef typename Mybase::value_type                                 value_type;
            typedef typename Mybase::difference_type                            difference_type;
            typedef typename Mybase::pointer                                    pointer;
            typedef typename Mybase::reference                                  reference;


            /* Constructor */
            const_iterator(): Ptr(0){};

            /* Constructor */
            const_iterator(Nodeptr P): Ptr(P){};

            const_iterator(const typename Tree<Tree_traits>::iterator X): Ptr(X.Mynode()){};

            /* Overload operator */
            const_reference operator*() const {return (Value(Ptr));}
            
            Ctptr operator->() const {return (&**this);}

            const_iterator &operator++()
            {
                Inc();
                return(*this);
            }

            const_iterator operator++(int)
            {
                const iterator Tmp = *this;
                
                ++*this;
                return (Tmp);
            }

            const_iterator &operator--()
            {
                Dec();
                return(*this);
            }

            const_iterator operator--(int)
            {
                const iterator Tmp = *this;
                
                --*this;
                return (Tmp);
            }


            bool operator==(const const_iterator X) const {return (Ptr == X.Ptr);}

            bool operator!=(const const_iterator X) const {!(*this == X);}

            void Dec()
            {
                if (Isnil(Ptr))
                    Ptr = Right(Ptr);
                else if (!Isnil(Left(Ptr)))
                {   
                    Ptr = Max(Left(Ptr));
                }
                else
                {
                    Nodeptr P;

                    while (!Isnil(P == Parent(Ptr)) && Ptr == Left(P))
                    {
                        Ptr = P;
                    }
                    if (!Isnil(P))
                    {
                        Ptr = P;
                    }
                }
            }

            void Inc()
            {
                if (Isnil(Ptr))
                    ;
                else if (!Isnil(Right(Ptr)))
                {   
                    Ptr = Min(Right(Ptr));
                }
                else
                {
                    Nodeptr P;

                    while (!Isnil(P == Parent(Ptr)) && Ptr == Right(P))
                    {
                        Ptr = P;
                    }
                }
            }

            Nodeptr Mynode() const;

        protected:
            Nodeptr Ptr;    
        };

        /* Reverse Iterator */

        typedef ft::reverse_iterator<iterator>              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

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

        ~Tree();

        Myt&operator=(const Myt & x);

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
        
        
        size_type size() const;

        size_type max_size() const;

        bool empty() const;

        allocator_type get_allocator() const;

        key_compare key_comp() const;

        value_compare value_comp() const;


        /*****************************************************/
        /*              Modifers                             */
        /*****************************************************/


        Pairib insert(const value_type & V);

        iterator insert(iterator P, const value_type &V);

        template<class It>
        void insert(It F, It L);

        iterator erase(iterator F, iterator L);

        size_type erase(const key_type& X);

        void erase(const key_type *F, const key_type *L);

        void clear();



        iterator find(const key_type & Kv);
        const_iterator find(const key_type & Kv) const;

        size_type count(const key_type & Kv) const;

        iterator lower_bound(const key_type & Kv);
        const_iterator lower_bound(const key_type & Kv) const;

        iterator upper_bound(const key_type & Kv);
        const_iterator upper_bound(const key_type & Kv) const;


        Pairii equal_range(const key_type & Kv);

        Paircc equal_range(const key_type & Kv) const;

        void swap(Myt &X);

    protected:
        void Copy(const Myt &X);

        Nodeptr Copy(Nodeptr X, Nodeptr P);

        void Erase(Nodeptr X);

        void Init();

        iterator Insert(bool Addleft, Nodeptr Y, const value_type &v);

        Nodeptr Lbound(const key_type &Kv);

        Nodeptr& Lmost();
        Nodeptr& Lmost() const;

        void Lrotate(Nodeptr X);

        static Nodeptr Max(Nodeptr P);

        static Nodeptr Min(Nodeptr P);

        Nodeptr& Rmost();
        Nodeptr& Rmost() const;

        Nodeptr& Root();
        Nodeptr& Root() const;

        void Rrotate(Nodeptr X);

        Nodeptr Ubound(const key_type& Kv) const;

        Nodeptr Buynode(Nodeptr Parg, char Carg);

        void Consval(Tptr P, const value_type& V);

        void Destval(Tptr P);

        void Freenode(Nodeptr S);

        Nodeptr     Head;
        size_type   Size;

    };
}

#include "xtree_constructor.hpp"
#include "xtree_get_allocator.hpp"
#include "xtree_function.hpp"

#endif