//http://codeforces.com/problemset/problem/625/C
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n, k;
	cin>>n>>k;
	
	int a[n][n], q = 0, x = n*n, sum = 0;
	
	memset(a,0,sizeof(a));
	
	for(int i = n-1; i >= 0; --i)
	{
		for(int j = n-1; j >= k-1; --j)
		{
			a[i][j] = x - q;
			q++;
		}
	}
	
	for(int i = n-1; i >= 0; --i)
	{
		for(int j = k-2; j >= 0; --j)
		{
			a[i][j] = x - q;
			q++;
		}
	}
	
	for(int i = 0; i < n; ++i)
		sum += a[i][k-1];
	
	cout<<sum<<'\n';

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			cout<<a[i][j]<<" ";
		cout<<'\n';
	}
	return 0;
}