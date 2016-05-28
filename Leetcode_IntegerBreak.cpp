#include <bits/stdc++.h>
using namespace std;

int integerBreak(int n) 
{
    int dp[n+1] = {0};
    dp[1] = 1;

    for(int i = 2; i <= n; i++) 
        for(int j = 1; 2 * j < i; j++)
            dp[i] = max(dp[i], (max(j,dp[j]) * max(i-j,dp[i-j])));

    return dp[n];
}

int main(int argc, char const *argv[])
{
	int k;
	cin>>k;

	cout<<integerBreak(k);	
	return 0;
}