#ifndef FT_ITERATOR_TAG
# define FT_ITERATOR_TAG

namespace ft
{	

	/* Грубо говоря мы здесь все обьявляем */
	struct input_iterator_tag;
	struct output_iterator_tag;
	struct forward_iterator_tag;
	struct bidirectional_iterator_tag;
	struct random_access_iterator_tag;
	//typedef long int ptrdiff_t ;

	struct output_iterator_tag
	{

	};

	struct input_iterator_tag
	{

	};

	/* Однонаправленный */
	struct forward_iterator_tag : public input_iterator_tag
	{

	};

	/* Можно итерироваться назад */
	struct bidirectional_iterator_tag: public forward_iterator_tag 
	{

	};

	/* Хоть как можно */
	struct random_access_iterator_tag: public bidirectional_iterator_tag 
	{
		
	};

	/* Для того чтобы аонимать что пришел стандартный тип */
	struct Int_iterator_tag
	{

	};
	
	template <class It>
	struct iterator_traits;
	
	template <class T>
	struct iterator_traits<T *> ;

	template <class RanIt>
	class reverse_iterator;
}

#endif