#include "../STL/set/set.hpp"
#include "../STL/map/map.hpp"
//#include "../STL/set/multiset.hpp"

#include <iostream>
#include <set>
#include <iostream>
#include <vector>


int main()
{
	ft::set<int> tmp;
	std::set<int> tmp_;

	ft::set<int> tmp2;

	for (int i = 0; i < 100; i += 10)
	{
		tmp.insert(i);
		tmp_.insert(i);
	}
	
	// ft::set<int>::iterator it = tmp.lower_bound(30);
	// std::set<int>::iterator it_ = tmp_.lower_bound(30);
	
	// std::cout << *it << std::endl;
	// std::cout << *it_ << std::endl;


	ft::set<int>::iterator it = tmp.find(11);
	std::cout << *it << std::endl;

	tmp.key_comp();
	//tmp_.key_comp
	//tmp.




	return (0);
}