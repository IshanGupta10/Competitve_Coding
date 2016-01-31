//http://codeforces.com/contest/609/problem/B
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define LL long long

int arr[15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x;
  	cin>>n>>m;
  	
  	for(int i=0;i<n;i++)
  	{
    	cin>>x;
    	arr[x]++;
  	}
  	
  	LL res = 0;
  	
  	for(int i=1;i<=m;i++)
    	for(int j=i+1;j<=m;j++)
      		res += arr[i] * 1LL * arr[j];
  	
  	cout << res << '\n';
  	return 0;
}