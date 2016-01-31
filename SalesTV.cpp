#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m,sum=0,t;
	vector<int> v;
	cin>>n>>m;
	
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
	}

	sort(v.begin(),v.end());
	
	for (int i = 0; i < m; ++i)
		if(v[i] <= 0)
			sum += (-1*v[i]);
	cout<<sum<<'\n';
	return 0;
}