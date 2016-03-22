//http://codeforces.com/contest/631/problem/B
#include <iostream>
#include <cstring>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k, c, r, o;
	cin>>n>>m>>k;
	int a[n][m];
	memset(a,0,sizeof(a));
	while(k--)
	{
		cin>>c>>r>>o;
		if(c == 1)
			for(int i = 0; i < m; ++i)
				a[r-1][i] = o;
		else
			for(int i = 0; i < n; ++i)
				a[i][r-1] = o;
 
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			cout<<a[i][j]<<" ";
		cout<<'\n';
	}
	return 0;
}