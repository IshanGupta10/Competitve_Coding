#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

map<ll, ll> mp;

void primeFactors(ll n)
{
    // Prll the number of 2s that divide n
    while (n%2 == 0)
    {
        if(mp.find(2)!=mp.end())
        	mp[2]++;
        n = n/2;
    }
 
    for (ll i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            if(mp.find(i)!=mp.end())
        		mp[i]++;
            n = n/i;
        }
    }

    if (n > 2)
    	if(mp.find(n)!=mp.end())
        	mp[n]++;
}

int main(int argc, char const *argv[])
{
	ll t,q,l,r,n;
	cin>>t;
	vector<ll> v;
	while(t--)
	{
		cin>>n>>q;
		for (ll i = 0; i < n; ++i)
		{
			cin>>l;
			v.push_back(l);
		}
		cin>>l>>r;
		for (int i = l-1; i < r; ++i)
		{
			primeFactors(i);
		}
		for (std::map<ll,ll>::iterator i = mp.begin(); i != mp.end(); ++i)
		{
			if()
		}
	}
	return 0;
}