// http://codeforces.com/contest/676/problem/A
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, loc1, loc2, diff1, diff2, diff3, maxval;
	cin>>n;
	int a[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	for (int i = 0; i < n; ++i)
	{
		if(a[i] == 1)
			loc1 = i + 1;
		if (a[i] == n)
			loc2 = i + 1;
	}

	diff1 = abs(loc1 - loc2);

	if(loc1 > loc2)
	{
		diff2 = n - loc2;
		diff3 = loc1 - 1;
		maxval = max(diff1, max(diff2, diff3));
	}

	if(loc2 > loc1)
	{
		diff2 = n - loc1;
		diff3 = loc2 - 1;
		maxval = max(diff1, max(diff2, diff3));
	}
	
	cout<<maxval<<'\n';

	return 0;
}