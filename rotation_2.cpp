#include <iostream>
using namespace std;
#define NOB 32

unsigned int reverseBits(unsigned int n)
{
	unsigned int rev_num = 0, i, temp, z;
	for (i = 0; i < NOB; i++)
    {
    	z = 1 << i;
        temp = n & z;
        if(temp)
            rev_num = rev_num | (1 << ((NOB - 1) - i));
    }
    return rev_num;
}

int main()
{
	unsigned int k = 3;
	unsigned int c = reverseBits(k);
	cout<<c<<'\n';
	return 0;
}