// http://codeforces.com/problemset/problem/691/A
#include <iostream>
using namespace std;

int main() 
{
    int n, ans = 0;
    cin>>n;
    int a[n];
    
    for(int i = 0; i < n; ++i)
    {
        cin>>a[i];
        if(a[i] == 0)
        	ans++;
    }
    
    if(n == 1 && ans == 1)
    	cout<<"NO"<<'\n';
    else if(n == 1 && ans == 0)
    	cout<<"YES"<<'\n';
    else if(n > 1 && ans > 1)
    	cout<<"NO"<<'\n';
    else if(n> 1 && ans == 1)
    	cout<<"YES"<<'\n';
    else if(n> 1 && ans > 1)
    	cout<<"NO"<<'\n';
    else
        cout<<"NO"<<'\n';
	return 0;
}