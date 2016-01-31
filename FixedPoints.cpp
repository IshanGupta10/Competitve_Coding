//http://codeforces.com/problemset/problem/347/B
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,t;
	cin>>n;
	vector<int> v,t;
	
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
	}

	for (int i = 0; i < n; ++i)
		t.push_back(v[i]-i);

	sort(t.begin(),t.end());
	return 0;
}