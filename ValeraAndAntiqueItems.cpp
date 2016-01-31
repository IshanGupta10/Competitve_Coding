//http://www.codeforces.com/problemset/problem/441/A
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
	int n, t, x, value, count = 0;
	vector<int> row,location;
	vector<vector<int> > v;
	cin>>n>>value;
	for(int j = 0; j < n; ++j)
	{
		cin>>t;
		v.push_back(row);
		for(int i = 0; i < t; ++i)
		{
			cin>>x;
			v[j].push_back(x);
		}
		sort(v[j].begin(),v[j].end());
	}
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<v[i].size();j++)
	// 		cout<<v[i][j]<<" ";
	// 	cout<<'\n';
	// }
	for(int i = 0; i < n; ++i)
		if(value > v[i][0])
		{
			count++;
			location.push_back(i+1);
		}
	
	cout<<count<<'\n';
	if(count)
		for(int i = 0; i < count; ++i)
			cout<<location[i]<<" ";
	return 0;
}