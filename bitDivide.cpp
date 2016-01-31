#include <iostream>
#include <climits>
using namespace std;

int bitSubtract(int x, int y)
{
    while (y != 0)
    {
        int borrow = (~x) & y;
        x = x ^ y;
 		y = borrow << 1;
    }
    return x;
}
int divide(int dividend,int divisor) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	long int dividen,diviso;
	dividen = dividend;
	diviso = divisor;
	if(dividend == INT_MIN && divisor==-1)
		return INT_MAX;
	if(dividend == INT_MIN && divisor==1)
		return INT_MIN;
    // if(dividen > INT_MAX)
    // 	return INT_MAX;
    // if(diviso > INT_MAX)
    //     return INT_MAX;
    // if(dividen < INT_MIN)
    // 	return INT_MAX;
    // if(diviso < INT_MIN)
    //     return INT_MAX;
    int dis=0,di=0;
    long int quotnt=0,rem=0;
    //  cout<<"dividen "<<dividen<<endl;
    //  cout<<"diviso "<<diviso<<endl;
    if(dividen < 0)
    {
        di = dividen;
        dividen = -1*dividen;
    }
    if(diviso < 0)
    {
        dis = diviso;
        diviso = -1*diviso;
    }
    //  cout<<"Di "<<di<<endl;
    //  cout<<"Dis "<<dis<<endl;
    if(diviso == 0)
    	return INT_MAX;
    for(int i=31;i>=0;i--)
    {
    	quotnt <<= 1;
        rem <<= 1;
        rem = rem | (dividen & (1 << i)) >> i;

        if(rem >= diviso)
        {
            rem = bitSubtract(rem, diviso);
            quotnt = quotnt | 1;
        }
    }
    // cout<<"Quotient "<<quotnt<<endl;
    if(dis<0 && di>=0) 
    {   
        if(quotnt > INT_MAX)
    	    return INT_MAX;
        else
    	    return -1*quotnt;
    }
    if(dis>=0 && di<0)
    {   
        if(quotnt > INT_MAX)
    	    return INT_MAX;
        else
    	    return -1*quotnt;
    }
    if(dis<0 && di<0)
    {   
        if(quotnt > INT_MAX)
    	    return INT_MAX;
        else
    	    return quotnt;
    }
    if(dis==0 && di==0)
    {   
        if(quotnt > INT_MAX)
    	    return INT_MAX;
        else
    	    return quotnt;
    }
}


int main(int argc, char const *argv[])
{
	int a,b,ans;
	cin>>a>>b;
	ans = divide(a,b);
	cout<<ans;
	return 0;
}