//http://codeforces.com/contest/621/problem/A
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

int main() 
{
	ulli sum = 0, x, n;
	cin>>n;
	vector<ulli> v;

	for(int i =0; i<n;++i)
	{
		cin>>x;
		v.push_back(x);	
	}

	sort(v.begin(),v.end());

	for(auto i:v)
	{
		sum+=i;	
	}

	if(n == 1)
	{
		if(v[0]%2 == 0)
			cout<<v[0]<<'\n';
		else
			cout<<0<<'\n';
	}
	else if(sum%2 == 0)
		cout<<sum<<'\n';
	else
	{
		for(auto i:v)
		{
			if(i%2 != 0)
			{
				sum -= i;
				break;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
