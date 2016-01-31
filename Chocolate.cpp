//http://codeforces.com/contest/617/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == 0)
			dp[i] = dp[i-1];
		if(a[i] == 1)
		{
				dp[i] += dp[i-1];
				for(int  j = i-1; a[j] == 0 && j >= 1;j--)
					dp[i] += dp[j-1];
				if(dp[i-1] == 0)
					dp[i] = 1;
		}
	}
	cout<<dp[n]<<'\n';
	return 0;
}