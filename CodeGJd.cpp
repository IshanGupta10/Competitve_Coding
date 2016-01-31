//https://www.hackerearth.com/january-easy-16/algorithm/code-gjd/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;
int main() 
{
	ulli t, n, val, ans = 0, temp = 0;
	vector<int> v;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 0; i < n; ++i)
		{
			cin>>val;
			v.push_back(val);
		}
		sort(v.begin(),v.end(),greater<int>());
		temp = v[0] + v[1];
		ans = temp;
		for(int i = 2; i < n; ++i)
		{
			temp += v[i]; 
			ans +=  temp;
		}
		v.clear();
		cout<<ans<<'\n';
	}
	return 0;
}