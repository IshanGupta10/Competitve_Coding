//http://codeforces.com/contest/612/problem/B
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,t;
	long long sum = 0;
	cin>>n;
	map<int,int> mp;
	
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		mp[t] = i+1;
	}
	
	for (int i = 1; i < n; ++i)
		sum += abs(mp[i] - mp[i+1]);
	
	cout<<sum<<'\n';
	return 0;
}