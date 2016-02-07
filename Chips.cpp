//codeforces.com/problemset/problem/92/A
#include <iostream>
using namespace std;

int main() 
{
	int n, m, flag = 0;
	cin>>n>>m;
	while(1)
	{
		for(int i = 1; i <= n; i++)
			if(m >= i)
				m -= i;
			else
			{
				flag = 1;
				break;
			}
		if(flag)
			break;
	}
	cout<<m<<'\n';
	return 0;
}