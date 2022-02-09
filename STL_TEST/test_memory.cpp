#include <iostream>
#include "../STL/memory/memory.hpp"

#include <assert.h>

static size_t cnt;

class Myint
{
public:
    
    Myint(int x): val(x)
    {
        cnt++;
    }

    Myint(const Myint &x) : val(x.val)
    {
        cnt++;
    }
    
    ~Myint()
    {
        cnt--;
    }

    int get_val() const
    {
        return val;
    }

private:

    int val;

};


typedef ft::allocator<float> Myal;

Myal get_al()
{
    return Myal();
}

/*
**
** Testing Allocator
**
*/

void test_alloc()
{
    float f1;
    Myal::size_type *p_size = (size_t *)0;
    Myal::difference_type *p_val = (ptrdiff_t *)0;
    Myal::pointer *p_ptr = (float **)0;
    Myal::const_pointer *p_cptr = (const float **)0; 
    Myal::reference  p_ref = f1; 
    Myal::const_reference p_cref = (const float &)f1;
    Myal::value_type *p_dist = (float *)0;
    Myal::rebind<int>::other::pointer *p_iptr = (int **)0;
    Myal al0 = get_al();
    Myal al(al0);
    
    //Myal::allocator<void>::pointer *pv_ptr = (void **)0;
	//Myal::allocator<void>::const_pointer *pv_cptr = (const void **)0;
	//std::allocator<void>::const_pointer *pv_cptr = (const void **)0;
    Myal::rebind<int>::other::pointer *pv_iptr = (int **)0;

	//ft::allocator<void> alv0,alv(alv0);
	//alv = alv0;

	float *pf1 = al0.address(f1);
	assert(pf1 == &f1);

    pf1 = al.allocate(3, 0);
	al.construct(&pf1[2], 2.0F);
	assert(pf1[2] == 2.0F);

	al.destroy(pf1);

	al.deallocate(pf1,1);

	assert(0 < al0.max_size());
	//assert(al0 == al);
	//assert()
	al0.destroy(pf1);
	//al0.deallocate(pf1,1);
}


int main()
{
    test_alloc();
    std::cout << GREEN <<"Success testing <memory> \n" << F_NONE;

    return (0);
}