//http://codeforces.com/problemset/problem/230/A
#include <iostream>
using namespace  std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int s,n,x,y,flag = 0;
	cin>>s>>n;
	while(n--)
	{
		cin>>x>>y;
		if(s >= x)
		{
			s += y;
			flag = 0;
		}
		else
			flag = 1;
	}
	if(flag)
		cout<<"NO"<<'\n';
	else
		cout<<"YES"<<'\n';
	return 0;
}