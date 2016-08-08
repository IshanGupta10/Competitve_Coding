//http://codeforces.com/problemset/problem/705/B
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long n, sum = 0, val = 0;
	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		cin>>val;
		sum += (--val);
		if(sum % 2 == 0)
			cout<<2<<'\n';
		else
			cout<<1<<'\n';
	}

	return 0;
}