#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, n, m, x;
	bool will = true;
	vector<int> b,g;

	cin>>t;
	
	while(t--)
	{
		cin>>n>>m;
		for (int i = 0; i < n; ++i)
		{
			cin>>x;
			b.push_back(x);
		}
	
		for (int i = 0; i < m; ++i)
		{
			cin>>x;
			g.push_back(x);
		}
		
		sort(b.begin(),b.end());
		sort(g.begin(),g.end());
		
		//cout<<b.size()<<'\n';
		//cout<<g.size()<<'\n';
		for (int i = 0; i < n; ++i)
		{
			int k = upper_bound(g.begin(),g.end(),b[i]) - g.begin();
			if(g[k-1] > b[i])
			{
				will = false;
				break;
			}
		}
		
		b.clear();
		g.clear();
		
		if(will)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	}
	return 0;
}