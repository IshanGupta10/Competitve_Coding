//http://codeforces.com/problemset/problem/218/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m,t,max = 0, min = 0;
	cin>>n>>m;
	vector<int> v,x;
	
	for (int i = 0; i < m; ++i)
	{
		cin>>t;
		v.push_back(t);
		x.push_back(t);
	}

	t = n;
	sort(v.begin(), v.end(), greater<int>());
	sort(x.begin(),x.end());

	for(int i = 0; i < v.size(); ++i)
	{
		if(n <= 0)
			break;
		else
		{
			while(v[i] != 0)
			{
				if(v[i] < v[i+1])
					break;
				cout<<"v["<<i<<"] "<<v[i]<<" ";
				max += v[i];
				cout<<"max "<<max<<" ";
				v[i]--;
				n--;
				cout<<"n "<<n<<" ";
				cout<<'\n';
				if(n <= 0)
					break;
			}
			
		}
	}
	
	cout<<'\n';
	
	for(int i = 0; i < x.size(); ++i)
	{
		if(t <= 0)
			break;
		else
		{
			while(x[i] != 0)
			{
				min += x[i];
				cout<<"min "<<min<<" ";
				x[i]--;
				t--;
				cout<<"t "<<t<<" ";
				if(t <= 0)
					break;
			}
			
		}
	}
	cout<<'\n'<<"final max "<<max;
	cout<<'\n'<<"final min "<<min<<'\n';
	cout<<max<<" "<<min<<'\n';
	return 0;
}