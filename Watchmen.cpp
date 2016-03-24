//http://www.codeforces.com/problemset/problem/650/A
#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main(int argc, char const *argv[])
{
	map<int,int> xs, ys;
	map<pair<int,int>,int> z;
	unsigned long long int ans = 0;
	int n;

	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin>>x>>y;
		ans += xs[x]++;
		ans += ys[y]++;
		ans -= z[make_pair(x,y)]++;
	}
	cout<<ans<<'\n';
	return 0;
}