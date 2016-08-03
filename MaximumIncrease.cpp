//http://codeforces.com/contest/702/problem/A
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int n, t, maxi = 0, count = 1;
	vector<int> v;

	cin>>n;

	int a[n+1] = {0};

	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
	}

	a[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		if(i < n && v[i] > v[i - 1])
		{
			count++;
			a[i] = max(count, a[i - 1]);
		}
		else
		{	
			count = 1;
			a[i] = max(count, a[i - 1]);
		}
	}

	cout<<a[n]<<'\n';

	return 0;
}