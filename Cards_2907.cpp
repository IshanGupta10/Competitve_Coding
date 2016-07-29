// http://codeforces.com/problemset/problem/701/A
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	vector<int> v, x;
	int n, t;
	bool flag = true; 
	
	cin>>n;
	
	for(int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
	}
	
	for (int i = 1; i < n; ++i)
	{
		if(v[i] != v[i - 1])
		{
			flag = false;
			break;
		}
	}

	x = v;
	t = 0;
	
	sort(x.begin(), x.end());
	
	if(!flag)
	{	
		while(t < (x.size() / 2))
		{
			int a = find(v.begin(), v.end(), x[t]) - v.begin();
			v.at(a) = INT_MIN;
			int b = find(v.begin(), v.end(), x[n - t - 1]) - v.begin();
			v.at(a) = INT_MIN;
			cout<<a + 1<<" "<<b + 1<<'\n';
			t++;
		}
	}
	else
	{
		while(t < x.size() / 2)
		{
			cout<<t + 1<<" "<<n - t<<'\n';
			t++;
		}
	}	
	
	return 0;
}