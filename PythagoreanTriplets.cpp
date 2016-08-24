//http://codeforces.com/problemset/problem/707/C
#include <iostream>
using namespace std;

int main()
{
    int n;

    cin>>n;
    n *= n;

    if(n < 5)
        cout<<-1;
    else if(n % 4)
        cout<<n/2<<" "<<(n/2)+1;
    else
        cout<<(n/4 - 1)<<" "<<(n/4 + 1);
    return 0;
}