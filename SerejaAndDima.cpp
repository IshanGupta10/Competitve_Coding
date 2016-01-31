//http://codeforces.com/problemset/problem/381/A
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> v;
	int n,t,sereja=0,dima=0,i;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		v.push_back(t);
	}
	i = 0;
	while(n > i)
	{
		if(i%2 == 0)
		{
			if(v[i]>v[n-1])
			{
				sereja += v[i];
				i++;
			}
			else
			{
				sereja += v[n-1];
				n = n-1
			}
		}
		else
		{
			if(v[i]>v[n-1])
			{
				dima += v[i];
				i++;
			}
			else
			{
				dima += v[n-1];
				n = n-1;
			}
		}
	}

	cout<<sereja<<" "<<dima<<'\n';
	return 0;
}
