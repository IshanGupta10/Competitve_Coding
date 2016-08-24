#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

map<ulli, int> mp;

int main(int argc, char const *argv[])
{
	int n, a;
	ulli ans = 0;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> a;

		for(int j = 0; j <= 30; j++)
		{
			int power = (1 << j);
			
			if(mp.find(power - a) == mp.end())
				ans += 0;
			else
				ans += mp[power - a];
		}

		mp[a]++;
	}

	cout<<ans<<'\n';
	return 0;
}