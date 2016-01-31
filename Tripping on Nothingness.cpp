//https://www.hackerearth.com/january-easy-16/algorithm/tripping-on-nothingness/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if( a<0 ) a = -a;
    if( b<0 ) b = -b;
    while( b!=0 )
    {
        a %= b;
        if( a==0 ) return b;
        b %= a;
    }
    return a;
}

int main() 
{
	map<int,int> mp;
	vector<int> v;
	int s, q, x, p;
	cin>>s>>q;
	for(int i = 0; i < q; ++i)
	{
		cin>>x;
		p = gcd(s,x);
		if(mp.find(p) != mp.end())
			cout<<-1<<'\n';
		else
		{
			mp[p] = 1;
			cout<<p<<'\n';
		}
	}
	return 0;
}