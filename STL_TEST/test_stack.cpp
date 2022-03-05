#include "../STL/stack/stack.hpp"
#include <iostream>


void test_stack()
{
    ft::stack<int> stack;
	ft::stack<int> stack1;

	assert(stack1.empty());
	for (int i = 0; i < 30; i++)
		stack1.push(i);
	assert(!stack1.empty());
	assert(stack1.size() == 30);
	stack.swap(stack1);
	assert(stack1.empty());

	while (!stack.empty()) {
	std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << std::endl;
    
}

int main()
{
	test_stack();
    std::cout << GREEN <<"SUCCESS testing  <stack>" <<  F_NONE <<std::endl;

    return (0);
}