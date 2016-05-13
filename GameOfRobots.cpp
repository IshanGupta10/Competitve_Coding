#include <bits/stdc++.h>
using namespace std;

int main() 
{
	vector<int> v;
	int n, k, t, sum = 0, flag = 1;
	
	cin>>n>>k;
	
	for(int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
	}
	
	while(sum <= k)
	{
		sum += flag;
		flag++;
	}
	
	val = sum - k;
	
	cout<<v[--val];
	
	return 0;
}