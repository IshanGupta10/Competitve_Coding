//http://codeforces.com/gym/100889/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	vector<int> v;
	int t, n, val, x;
	unsigned long long int sum = 0;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		for(int i = 0; i < n; ++i)
		{
			cin>>val;
			v.push_back(val);
		}
		
		sort(v.begin(),v.end());
		x = v.size();
	
		for(int i = 0; i < x/2; ++i)
			sum += (v[x - i - 1] - v[i]);
		
		cout<<sum<<'\n';
		sum = 0;
		v.clear();
	}
	return 0;
}