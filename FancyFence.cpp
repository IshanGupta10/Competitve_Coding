//http://codeforces.com/problemset/problem/270/A
#include <iostream>
using namespace  std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,a,rem;
	cin>>t;
	while(t--)
	{
		cin>>a;
		rem = 360 % (180-a);
		if(rem)
			cout<<"NO"<<'\n';
		else
			cout<<"YES"<<'\n';
	}
	return 0;
}