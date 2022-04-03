#include "../STL/set/set.hpp"
#include "../STL/map/map.hpp"
//#include "../STL/set/multiset.hpp"

#include <iostream>
#include <set>
#include <iostream>
#include <vector>


int main()
{
	// ft::set<int> tmp;
	// std::set<int> tmp_;

	// ft::set<int> tmp2;

	// for (int i = 0; i < 100; i += 10)
	// {
	// 	tmp.insert(i);
	// 	tmp_.insert(i);
	// }
	
	// // ft::set<int>::iterator it = tmp.lower_bound(30);
	// // std::set<int>::iterator it_ = tmp_.lower_bound(30);
	
	// // std::cout << *it << std::endl;
	// // std::cout << *it_ << std::endl;


	// ft::set<int>::iterator it = tmp.find(11);
	// std::cout << *it << std::endl;

	// tmp.key_comp();
	// //tmp_.key_comp
	// //tmp.

	ft::map<int, int> tmp;

	for(int i = 0; i < 10; i++)
	{
		tmp.insert(ft::make_pair(i, i * i));
	}


	std::cout << tmp[9] << std::endl;
	std::cout << tmp.at(9) << std::endl;


	std::cout << (*tmp.find(5)).first << std::endl;



	return (0);
}