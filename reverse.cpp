#include <iostream>
#include <cmath>
using namespace std;
int reverse(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A > 2147483647 || A < -2147483648)
    //if(A > INT_MAX || A < INT_MIN)
    return 0;
    unsigned int reverse = 0,n;
    n = A;
    if(A < 0)
    {
        A = -1 * A;
        cout<<"New A "<<A<<'\n';
    }
    while(A > 0)
    {
        if((reverse*10 + A%10) > 2147483647)
            return 0;
        reverse = reverse*10 + A%10;
        cout<<"reverse "<<reverse<<'\n';
        A = A/10;
        cout<<"A "<<A<<endl;
    }
    if(n > 0)
    return reverse;
    else
    return (-1 * reverse);
}
int main(int argc, char const *argv[])
{
    int n,t;
    cin>>n;
    t = reverse(n);
    cout<<t;
    return 0;
}