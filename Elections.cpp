////http://codeforces.com/problemset/problem/570/A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	vector<int> row;
	vector<vector<int> > v;
	int n, m, t, maxi = 0, index = -1;
	cin>>n>>m;
	
	for (int i = 0; i < m; ++i)
	{
		v.push_back(row);
		for (int j = 0; j < n; ++j)
		{
			cin>>t;
			v[i].push_back(t);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		
		for (int j = 0; j < m; ++j)
			sum += v[j][i];
		
		row.push_back(sum);
	}

	maxi = *max_element(row.begin(),row.end());

	for (int i = 0; i < row.size(); ++i)
	{
		if(maxi == row[i])
			if(index == -1)
				index = i+1; 
	}

	cout<<index<<'\n';
	return 0;
}