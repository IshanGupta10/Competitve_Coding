#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a,b,c,n;
    cin>>n>>a>>b>>c;
    ll cost = min (a,b-c);
    ll count =0;
    if(cost == b-c && n>=b)
    {
    	count = count + (n-b)/(cost)+1;
    	n -= (count*cost);
    	if(n>=a)
        	count+=(n/a);
    }
    else
    	count = count + n/a;
    cout<<count<<'\n';
    return 0;
}