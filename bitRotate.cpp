#include "iostream"
using namespace std;
int leftRotate(unsigned int n, unsigned int d)
{
   /* In n<<d, last d bits are 0. To put first 3 bits of n at 
     last, do bitwise or of n<<d with n >>(INT_BITS - d) */
   return (n << d)|(n >> (32 - d));
}
unsigned int reverse(unsigned int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	unsigned int d=A;
	unsigned int count=0;
	for(int i=31;i>=0;i--)
		if(d&0 == 0)
		{
			count++;
			d = d<<1;
		}
		else
			break;
	return leftRotate(A,count);
}
int main(int argc, char const *argv[])
{
	unsigned int S,r;
	cin>>S;
	r = reverse(S);
	cout<<r;
	return 0;
}