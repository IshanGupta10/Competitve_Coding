//http://codeforces.com/contest/710/problem/B
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	if(n == 1)
		cout<<a[0];
	else
	{
		sort(a, a+n);
		if(n%2 == 0)
			cout<<a[(n / 2) - 1]<<'\n';
		else
			cout<<a[n / 2]<<'\n';
	}
	return 0;
}