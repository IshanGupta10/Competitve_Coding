//http://codeforces.com/problemset/problem/4/C
#include <iostream>
#include <algorithm>
#include <string> 
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<string, int> mp;
	int n;
	cin>>n;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		if (mp.find(s) != mp.end())
		{
			cout<<s<<mp[s]<<'\n';
			mp[s]++;
		}
		else
		{
			mp[s] = 1;
			cout<<"OK"<<'\n';
		}
	}
	return 0;
}