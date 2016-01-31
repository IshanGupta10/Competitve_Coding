//http://codeforces.com/contest/611/problem/B
#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
    ll a, b, temp;
    cin>>a>>b;
    
    int ans = 0;
    for(ll i = 0; i < 61; ++i)
    {	
    	for(ll j = 0; j < i-1; ++j)
	    {    
	    	temp = (1ll<<i) - (1ll<<j) - 1;
	        if(temp >= a && temp <= b) 
	        	ans++;
	    }
    }
    
    cout<<ans<< '\n';
	return 0;
}