#include "../STL/set/set.hpp"
//#include "../STL/set/multiset.hpp"

#include <iostream>
#include <set>
#include <iostream>
#include <vector>

/* Include less */
#include "../STL/functional/functional.hpp"

//using namespace std;

void test_set()
{
	typedef std::allocator<char> Myal;
	typedef ft::less<char> Mypred;
	typedef ft::set<char, Mypred, Myal> Mycont;
	char ch, str1[] = "abc", str2[] = "def";

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
	assert(v0.size() == 3 && *v0.begin() == 'a');

	Mycont::iterator p_it(v1.begin());
	Mycont::const_iterator p_cit(v4.begin());
	Mycont::reverse_iterator p_rit(v1.rbegin());
	Mycont::const_reverse_iterator p_crit(v4.rbegin());
	assert(*p_it == 'a' && *--(p_it = v1.end()) == 'c');
	assert(*p_cit == 'a' && *--(p_cit = v4.end()) == 'c');
	assert(*p_rit == 'c' && *--(p_rit = v1.rend()) == 'a');
	assert(*p_crit == 'c' && *--(p_crit = v1.rend()) == 'a');

	v0.clear();
	ft::pair<Mycont::iterator, bool> pib = v0.insert('d');
	assert(*pib.first == 'd' && pib.second);
	assert(*--v0.end() == 'd');
	pib = v0.insert('d');
	assert(*pib.first == 'd');
	assert(!pib.second);

	assert(*v0.insert(v0.begin(), 'e') == 'e');
	v0.insert(str1, str1 + 3);
	assert(v0.size() == 5 && *v0.begin() == 'a');
	v0.insert(str2, str2 + 3);
	assert(v0.size() == 6 && *--v0.end() == 'f');
	assert(*v0.erase(v0.begin()) == 'b');
	assert(v0.size() == 5);
	assert(*v0.erase(v0.begin(), ++v0.begin()) == 'c' && v0.size() == 4);
	assert(v0.erase('x') == 0 && v0.erase('e') == 1);

	v0.clear();
	assert(v0.empty());
	v0.swap(v1);
	assert(!v0.empty() && v1.empty());
	ft::swap(v0, v1);
	assert(v0.empty() && !v1.empty());


	assert(v1 == v1);
	assert(v0 < v1);
	assert(v0 != v1 && v1 > v0);
	assert(v0 <= v1 && v1 >= v0);

	assert(v0.key_comp()('a', 'c') && !v0.key_comp()('a', 'a'));
	assert(v0.value_comp()('a', 'c') && !v0.value_comp()('a', 'a'));
	assert(*v4.find('b') == 'b');
	assert(v4.count('x') == 0 && v4.count('b') == 1);
	assert(*v4.lower_bound('a') == 'a');
	assert(*v4.upper_bound('a') == 'b');
	ft::pair<Mycont::const_iterator, Mycont::const_iterator> pcc = v4.equal_range('a');
	assert(*pcc.first == 'a' && *pcc.second == 'b');
}

// #define _set ft::set

// template <class T>
// std::vector<int> test_iter(_set<T> st)
// {
//     std::vector<int> v;
//     // fillSet(st);
    
//     ft::set<int, std::greater<int> > st_1;

// 	//std::cout << "proba1\n";
//     typename _set<T>::iterator it = st_1.begin();
// 	//std::cout << "proba2\n";
//     // for (typename _set<T>::iterator it = st.begin(); it != st.end(); it++) { v.push_back(*it); }
//     // for (typename _set<T>::iterator it = --st.end(); it != st.begin(); it--) { v.push_back(*it); }
//     // _set<int, std::greater<int> > st1;
    
//     // v.push_back(*(st1.begin()));
//     // st1.erase(41);
//     // v.push_back(*(st1.begin()));
//     // st1.erase(29);
//     // v.push_back(*(st1.begin()));
//     // _set<int, std::greater<int> > st2;
//     // st2.insert(3);
//     // v.push_back(*(st2.begin()));
//     // st2.erase(3);
//     // if (st2.begin() == st2.end())
//     //     v.push_back(1);
//     // _set<int, std::greater<int> > st3;

//     // for (typename _set<T>::iterator it = st3.begin(); it != st3.end(); it++) { v.push_back(*it); }
//     // for (typename _set<T>::iterator it = --st3.end(); it != st3.begin(); it--) { v.push_back(*it); }
//     // _set<int, std::minus<int> > st4;

//     // for (typename _set<T>::iterator it = st4.begin(); it != st4.end(); it++) { v.push_back(*it); }
//     // for (typename _set<T>::iterator it = --st4.end(); it != st4.begin(); it--) { v.push_back(*it); }
//     // _set<int, std::greater_equal<int> > st5;
//     // fillSet(st5);
//     // for (typename _set<T>::iterator it = st5.begin(); it != st5.end(); it++) { v.push_back(*it); }
//     // for (typename _set<T>::iterator it = --st5.end(); it != st5.begin(); it--) { v.push_back(*it); }
//     // _set<int, std::multiplies<int> > st6;
//     // fillSet(st6);
//     // for (typename _set<T>::iterator it = st6.begin(); it != st6.end(); it++) { v.push_back(*it); }
//     // for (typename _set<T>::iterator it = --st6.end(); it != st6.begin(); it--) { v.push_back(*it); }
//     // _set<int, std::bit_xor<int> > st7;
//     // fillSet(st7);
//     // for (typename _set<T>::iterator it = st7.begin(); it != st7.end(); it++) { v.push_back(*it); }
//     // for (typename _set<T>::iterator it = --st7.end(); it != st7.begin(); it--) { v.push_back(*it); }
//     // std::set<int, std::logical_and<int> > st8;
//     // fillSet(st8);
//     // for (typename std::set<T>::iterator it = st8.begin(); it != st8.end(); it++) { v.push_back(*it); }
//     // for (typename std::set<T>::iterator it = --st8.end(); it != st8.begin(); it--) { v.push_back(*it); }
//     // g_start1 = timer();
//     // g_end1 = timer();
//     // v.push_back(st1.size());

//     return v;
// }

#include <memory>
int main()
{
	//ft::set<int> st;
	//test_iter(st);

	//std::cout << "asd" << std::endl;
    
    test_set();
    std::cout << GREEN <<"SUCCESS testing  <set>" <<  F_NONE <<std::endl;

    return (0);
}