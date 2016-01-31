//http://codeforces.com/contest/618/problem/A
#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	vector<int> v;
	int x;
	cin>>x;
	if(x == 1)
		cout<<1<<'\n';
	else if(x == 2)
		cout<<2<<'\n';
	else
	{
		v.push_back(2);
		v.push_back(1);
		for(int i = 3; i < x; ++i)
		{
			v.push_back(1);
			int  k = v.size() - 1;
			while(v[k] == v[k-1])
			{
				int q = v[k];
				v.pop_back();
				v.pop_back();
				v.push_back(q+1);
				k--;
			}
			// for(auto i:v)
			// 	cout<<i<<" ";
			// cout<<'\n';
		}
	}
	for(auto i:v)
	 	cout<<i<<" ";
	cout<<'\n';
	return 0;
}