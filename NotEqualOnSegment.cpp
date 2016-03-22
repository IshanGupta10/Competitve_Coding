//http://codeforces.com/contest/622/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n, m, l, r, x, flag = 1;
	cin>>n>>m;
	int a[n];
	map<int,int> mp;
	for(int i = 0; i < n; ++i)
		cin>>a[i];
		
	while(m--)
	{
		cin>>l>>r>>x;
	//	cout<<l<<r<<x<<'\n';
		for(int i = l - 1; i < r; ++i)
		{
			if(x != a[i])
			{
				cout<<i+1<<'\n';
				flag = 0;
				break;
			}
		}
		if(flag)
			cout<<-1<<'\n';
		flag = 1;
	}
	return 0;
}