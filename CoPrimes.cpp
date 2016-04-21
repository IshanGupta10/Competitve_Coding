//http://codeforces.com/contest/660/problem/A
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int main(int argc, char const *argv[])
{
	vector<int> v,x;
	int n, t, k, count = 0;

	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
	}

	for (int i = 0; i < n-1; ++i)
		if(gcd(v[i],v[i+1]) != 1)
			count++;

	cout<<count<<'\n';

	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<" ";
		if(i < n-1 && gcd(v[i],v[i+1]) != 1)
			cout<<1<<" ";
	}

	return 0;
}