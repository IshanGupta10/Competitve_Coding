// http://codeforces.com/problemset/problem/697/A
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int t, s, x;
    cin>>t>>s>>x;
    
    if(x < t)
    {
        cout<<"NO"<<'\n';
        return 0;
    }
    
    if (x == t+1)
    {
        cout<<"NO"<<'\n';
        return 0;
    }
    
    x -= t;
    x %= s;
    
    if(x == 1)
    {
        cout<<"YES"<<'\n';
        return 0;
    }
    else if(x == 0)
    {
        cout<<"YES"<<'\n';
        return 0;
    }
    
    cout<<"NO"<<'\n';
    return 0;
}