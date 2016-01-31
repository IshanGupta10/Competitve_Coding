//http://codeforces.com/problemset/problem/447/A
#include <iostream>
#include <map>
using namespace std;

map<int,int> mp;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int p,n,x,aux=0,i,flag=0;
	cin>>p>>n;
	
	for (i = 0; i < n; ++i)
	{
		cin>>x;
		aux = x%p;
	//	cout<<aux<<" ";
	//	v.push_back(aux)
		if(mp.find(aux) == mp.end())
			mp[aux]=1;
		else
		{
			aux = i;
			flag = 1;
			break;
		}
	}
//	cout<<'\n';
	if(flag)
		cout<<i+1<<'\n';
	else
		cout<<-1<<'\n';
	return 0;
}