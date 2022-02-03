#ifndef FT_MEMORY
# define FT_MEMORY

#include "../utility/utility.hpp"

/* page 175 ... */

namespace ft
{
    template <class T>
   	class allocator
    {
        public:		
			typedef T					value_type;
			typedef T*					pointer;
			typedef const T*			const_pointer;
		    typedef T&					reference;
			typedef const T& 			const_reference;
			typedef size_t				size_type;
			typedef ptrdiff_t           difference_type;


            /* 
            ** Этот шаблонны класс определяет тип other 
            ** Его предназначение обеспечить доступность 
            ** allocator<U> имея обьект типа allocator<T>
            */
			template <class U>
			struct rebind
            {
				typedef allocator<U> other;
			};

			pointer address(reference value) const
            {
                return &value;
            }

			const_pointer address(const_reference value) const
            {
                return &value;
            }

			allocator() throw()
            {

            }

			allocator(const allocator&) throw()
            {

            }
			
            /* Создаем конструктор на основе другого типа */
            template <class U>
			allocator (const allocator<U>&) throw()
            {

            }

			~allocator() throw()
            {

            }
            
            size_type max_size() const
            {
                size_type N = (size_type)(-1) / sizeof(T);
                if (N > 0)
                {
                    return (N);
                }
                else
                {
                    return (1);
                }
            }

			pointer allocate(size_type num)
            {
                pointer ret;
                size_t  size = num * sizeof(value_type);

                try
                {
                    ret = reinterpret_cast<pointer>(::operator new(size));
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                return ret;
			}

			void construct(pointer p, const T& value)
            {
				new ((void*)p) T(value);
			}

			void destroy(pointer p) 
            {
				p->~T();
			}

			void deallocate(pointer p, size_type num)
            {
				(void)num;
				::operator delete((void*)p);
			}
   };

};

#endif