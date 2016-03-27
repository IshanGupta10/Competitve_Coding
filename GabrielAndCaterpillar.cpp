//http://www.codeforces.com/contest/652/problem/A
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int h1, h2, a, b, ans = 0, temp = 0;
	
	cin>>h1>>h2;
	cin>>a>>b;
	
	if(a < b)
	{
		if(h1 + a * 8 < h2)
			cout<<-1<<'\n';
		else
			cout<<0<<'\n';
	}
	else if(a == b)
	{
		if(h1 + a * 8 < h2)
			cout<<-1<<'\n';
		else
			cout<<0<<'\n';
	}
	else
	{
		while(h1 < h2)
		{
			if(temp == 0)
				h1 = h1 + a * 8;
			else
				h1 = h1 + a * 12;

			temp++;

			if(h1 > h2 && temp == 0)
			{
				cout<<0<<'\n';
				break;
			}

			if (h1 >= h2)
			{
				cout<<ans<<'\n';
				break;
			}

			h1 = h1 - 12 * b;
			ans++;
		}
	}
	return 0;
}