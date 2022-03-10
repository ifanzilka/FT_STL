    #include "../STL/set/set.hpp"
#include <iostream>

//using namespace std:

void test_set()
{
    // typedef std::allocator<char> Myal;
    // typedef std::less<char> Mypred;
    // typedef ft::set<char, Mypred, Myal> Mycont;
    // char ch, carr[] = "abc", carr2[] = "def";

    // Mycont::key_type        *p_key = (char *)0;
    // Mycont::key_compare     *p_komp = (Mypred *)0;
    // Mycont::value_type      *p_val = (char *)0;
    // Mycont::value_compare   *p_vcomp = (Mypred *)0;
    // Mycont::allocator_type  *p_alloc = (Myal *)0;
    // Mycont::pointer         p_ptr = (char *)0;
    // Mycont::const_pointer   p_cptr = (const char *)0;
    // Mycont::reference       p_ref = ch;
    // Mycont::const_reference p_cref = (const char &)ch;
    // Mycont::size_type       *p_size = (size_t *)0;
    // Mycont::difference_type *p_diff = (ptrdiff_t *)0;

    // Mycont v0;
    
    // Myal al = v0.get_allocator();
    // Mypred pred;
    // Mycont v0a(pred);
    // Mycont v0b(pred, al);

    // assert(v0.empty());
    // assert(v0.size() == 0);
    // assert(v0a.size() == 0 && v0a.get_allocator() == al);
    // assert(v0b.size() == 0 && v0b.get_allocator() == al);

    // Mycont v1(carr, carr + 3);
    // assert(v1.size() == 3 && *v1.begin() == 'a');

    typedef std::allocator<char> Myal;
	typedef std::less<char> Mypred;
	typedef ft::set<char, Mypred, Myal> Mycont;
	char ch, str1[] = "abc", carr2[] = "def";
    //std::cout << str1<<"\n";
	Mycont::key_type        *p_key = (char *)0;
	Mycont::key_compare     *p_komp = (Mypred *)0;
	Mycont::value_type      *p_val = (char *)0;
	Mycont::value_compare   *p_vcomp = (Mypred *)0;
	Mycont::allocator_type  *p_alloc = (Myal *)0;
	Mycont::pointer         p_ptr = (char *)0;
	Mycont::const_pointer   p_cptr = (const char *)0;
	Mycont::reference       p_ref = ch;
	Mycont::const_reference p_cref = (const char &)ch;
	Mycont::size_type       *p_size = (size_t *)0;
	Mycont::difference_type *p_diff = (ptrdiff_t *)0;

    Mycont v0;
    Myal al = v0.get_allocator();
	Mypred pred;
	Mycont v0a(pred), v0b(pred, al);

	assert(v0.empty() && v0.size() == 0);
	assert(v0a.size() == 0 && v0a.get_allocator() == al);
	assert(v0b.size() == 0 && v0b.get_allocator() == al);

	Mycont v1(str1, str1 + 3);
	assert(v1.size() == 3 && *v1.begin() == 'a');

    Mycont v2(str1, str1 + 3, pred);
	assert(v2.size() == 3 && *v2.begin() == 'a');

	Mycont v3(str1, str1 + 3, pred, al);
	assert(v3.size() == 3 && *v3.begin() == 'a');

	const Mycont v4(str1, str1 + 3);
	v0 = v4;
    // try
    // {
    //     v0 = v4;
    // }
    // catch(...)
    // {
        
    // }
    
    //std::cout << v0.size() << "\n"; 
	assert(v0.size() == 3); 
	
    assert(*v0.begin() == 'a');

	// std::cout << "start\n";

	Mycont::iterator p_it(v1.begin());
	Mycont::const_iterator p_cit(v4.begin());
	Mycont::reverse_iterator p_rit(v1.begin());
	Mycont::const_reverse_iterator p_crit(v4.begin());

	assert(*p_it == 'a');

	// p_it = v1.end();
	// --p_it;

	//std::cout << "!" << *(p_it) << "!" << std::endl;

    assert(*--(p_it = v1.end()) == 'c');

    assert(*p_cit == 'a' && *--(p_cit = v4.end()) == 'c');
	
	std::cout << *p_rit << "\n";
	assert(*p_rit == 'c');
	
	assert(*--(p_rit = v1.rend()) == 'a');
	assert(*p_crit == 'c' && *--(p_crit = v1.rend()) == 'a');

	// v0.clear();
	// ft::pair<Mycont::iterator, bool> pib = v0.insert('d');
	// cout << *v0.begin() << endl;
	// assert(*pib.first == 'd' && pib.second);
	// assert(*--v0.end() == 'd');
	// pib = v0.insert('d');
	// assert(*pib.first == 'd' && !pib.second);
	// assert(*v0.insert(v0.begin(), 'e') == 'e');
	// v0.insert(str1, str1 + 3);
	// assert(v0.size() == 5 && *v0.begin() == 'a');
	// v0.insert(str2, str2 + 3);
	// assert(v0.size() == 6 && *--v0.end() == 'f');
	// cout << *--v0.end() << endl;
	// cout << *--v0.begin() << endl;

	
	//assert(*v0.erase(v0.begin()) == 'b' && v0.size() == 5);

//	assert(*v0.erase(v0.begin(), ++v0.begin()) == 'c' && v0.size() == 4);
//	assert(v0.erase('x') == 0 && v0.erase('e') == 1);
//
//	v0.clear();

}

#include <iostream>
#include <set>
int main()
{

    test_set();
    std::cout << GREEN <<"SUCCESS testing  <set>" <<  F_NONE <<std::endl;

    return (0);
}