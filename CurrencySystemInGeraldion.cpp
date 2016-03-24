//http://www.codeforces.com/contest/560/problem/A
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, ans  = 1;

	cin>>n;
	
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		if(x == 1)
			ans = -1;
	}

	cout<<ans<<'\n';
	return 0;
}