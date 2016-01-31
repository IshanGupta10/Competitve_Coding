//http://codeforces.com/problemset/problem/231/A
#include <iostream>
#include <map>
using namespace std;
map<int,int> mp;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,t,count=0;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= 2; j++)
		{
			cin>>t;
			if(t==1)
				mp[i]++;
		}
	}
	for(int i = 0; i < n; i++)
		if(mp[i]>1)
			count++;
	cout<<count<<'\n';
	return 0;
}