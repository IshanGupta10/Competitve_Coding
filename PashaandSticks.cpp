//http://codeforces.com/contest/610/problem/0
#include <iostream>
using namespace std;

typedef long long ll;

int main() 
{
	ll len,sum = 0;
	cin>>len;
	if(len%2 == 0)
		sum = len/4 -1 + (len/2)%2;
	else
		sum = 0;
	cout<<sum<<'\n';
	return 0;
}