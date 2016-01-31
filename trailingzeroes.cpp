#include <iostream>
#include <cmath>
using namespace std;
int trailingZeroes(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count=0,power=1,i=1,K;
    while((A/power) > 0)
    {
        power = pow(5,i);
        cout<<"power "<<power<<'\n';
        K = A/power;
        cout<<"A "<<K<<'\n';
        count+=K;
        i++;
    }
    return count;
}
int main(int argc, char const *argv[])
{
	int n,t;
	cin>>n;
	t = trailingZeroes(n);
	cout<<t;
	return 0;
}