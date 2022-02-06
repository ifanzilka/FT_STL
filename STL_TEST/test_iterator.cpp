#include <iostream>
#include "../STL/utility/utility.hpp"
#include <assert.h>

typedef char *PtrIt;

// Тестирование основынх свойств
void takes_ran_tag()
{
	std::random_access_iterator_tag *ran_tag_s	= (std::random_access_iterator_tag *)0;

	std::bidirectional_iterator_tag	*bid_tag_s	= (std::bidirectional_iterator_tag *)0;

	std::forward_iterator_tag 		*fwd_tag_s	= (std::random_access_iterator_tag *)0;

	std::input_iterator_tag 		*in_tag_s	= (std::input_iterator_tag *)0;

	std::output_iterator_tag 		*p_out_tag_s	= (std::output_iterator_tag *)0;

	/* Делаем сокращенное имя */
	typedef std::iterator<std::input_iterator_tag, float, short, float*, float &> Iter;
	
	float f1;

	Iter::iterator_category *it_tag 	= (std::input_iterator_tag *)0;
	Iter::value_type 		*it_vals 	= (float*)0;
	Iter::difference_type	*it_dists 	= (short*)0;
	Iter::pointer			it_ptrs		= (float*)0;
	Iter::reference			it_refs		= f1;

	typedef std::iterator_traits<Iter> Traits;

	Traits::iterator_category	*tr_tags = (std::input_iterator_tag *)0;
	Traits::value_type 			*tr_vals = (float *)0;
	Traits::difference_type		*tr_dists = (short*)0;
	Traits::pointer				tr_ptrs = (float *)0;
	Traits::reference			tr_refs = f1;

	typedef std::iterator_traits<PtrIt> Ptraits;
	char chs;
	Ptraits::value_type 		*ptr_val = (char*)0;
	Ptraits::difference_type 	*ptr_dist = (std::ptrdiff_t *)0;
	Ptraits::pointer 			ptr_ptr = (char*)0;
	Ptraits::reference 			ptr_ref = chs;

	const char *pc = "abcdefg";
	std::advance(pc, 4);
	assert(*pc == 'e');
	std::advance(pc, -1);
	assert(*pc == 'd');

	assert(std::distance(pc, pc + 3) == 3);
}

void test_iterator()
{

}

int main()
{

	test_iterator();
	std::cout << GREEN <<"SUCCESS testing  <iterator>" <<  F_NONE <<std::endl;
	return (0);
};