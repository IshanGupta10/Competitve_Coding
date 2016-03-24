//http://www.codeforces.com/problemset/problem/653/A
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int args, char *argv[]) 
{
	int n, x;
	vector<int> v;
	cin>>n;
	
	for(int i = 0; i < n; ++i)
	{
		cin>>x;
		v.push_back(x);
	}
	
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	
	if(v.size() > 2)
	{
		for(int i = 0; i < v.size() - 2; ++i)
		{
		 	if(v[i+2] - v[i] == 2)
		 	{
		 		cout<<"YES";
		 		return 0;
		 	}
		}
	}
	cout<<"NO";
	return 0;
}