#include <iostream>
using namespace std;

#define INT_BITS 32
#define d 31
 
unsigned int doTheRotation(unsigned int n)
{
   return (n << d)|(n >> (INT_BITS - d));
}

int main() 
{
	unsigned int n,k;
	cin>>n;
	k = doTheRotation(n);
	cout<<k;
	return 0;
}