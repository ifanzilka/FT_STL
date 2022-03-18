#include <iostream>
#include <vector>
#include "../STL/vector/vector.hpp"
#include <thread>
#include <functional>
#include <map>

#define SIZE 100000000

# define F_NONE		"\033[37m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define CYANE		"\033[36m"
# define WHITE		"\033[1m"
# define YELLOW	    "\033[0;33m"
# define BLUE		"\033[34m" 
# define PURPLE     "\033[0;35m"
# define NORM		"\033[0m"

/* 
** Bold font  
** param [1; in range [1, 4]
*/

# define B_GRAY      "\033[1;30m"
# define B_WHITE     "\033[1;37m"
# define B_RED       "\033[1;31m"
# define B_YELLOW    "\033[1;33m"
# define B_GREEN     "\033[1;32m"
# define B_CYAN      "\033[1;36m"
# define B_BLUE      "\033[1;34m"
# define B_PURPLE    "\033[1;35m"

typedef std::chrono::microseconds mic;
typedef std::chrono::duration<float> Dur;
typedef std::chrono::high_resolution_clock hrc;
typedef std::chrono::steady_clock::time_point t_point;

std::vector<int> std_vec(SIZE);
ft::vector<int> ft_vec(SIZE);

void IterationSTD(){
	std::vector<int>::iterator it;
	it = std_vec.begin();
	for (int i = 0; it != std_vec.end(); i++, it++) {
		*it = i;
	}
	return ;
}

void IterationFT(){
	ft::vector<int>::iterator it;
	it = ft_vec.begin();
	for (int i = 0; it != ft_vec.end(); i++, it++) {
		*it = i;
	}
	return ;
}

void EraseSTD(){
	std_vec.erase(std_vec.begin(), std_vec.end());
}

void EraseFT(){
	ft_vec.erase(ft_vec.begin(), ft_vec.end());
}

void InsertSTD(){
	std_vec.insert(std_vec.begin(), SIZE, 7);
}

void InsertFT(){
	ft_vec.insert(ft_vec.begin(), SIZE, 7);
}

void AssignFT(){
	ft_vec.assign(SIZE, 5);
}

void AssignSTD(){
	std_vec.assign(SIZE, 5);
}

void ClearFT(){
	ft_vec.clear();
}

void ClearSTD(){
	std_vec.clear();
}

void Count_time(std::function<void()> f, std::function<void()> f1, const std::string& msg) {
	t_point start;
	t_point end;

	std::cout <<"Test " << msg << std::endl;
	start = hrc::now();
	f();
	end = hrc::now();
	Dur duration_std = end - start;
	
	start = hrc::now();
	f1();
	end = hrc::now();
	Dur duration_ft = end - start;

	std::cout.precision(5);	
	std::cout <<"std:: " << duration_std.count() << "s" << std::endl;
	std::cout.precision(5);	
	std::cout <<"ft::  " << duration_ft.count() << "s" << std::endl;
}

void test_vector()
{
    std::cout << GREEN <<"Test time vector start!" <<  F_NONE <<std::endl;
    Count_time(IterationSTD, IterationFT, "iteration");
	Count_time(EraseSTD, EraseFT, "erase");
	Count_time(InsertSTD, InsertFT, "insert");
	Count_time(AssignSTD, AssignFT, "assign");
	Count_time(ClearSTD, ClearFT, "clear");
}

int main (void){
    test_vector();

	return (0);
}