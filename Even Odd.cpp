#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n,k,x=0,q=0;
	cin>>n>>k;
	x = (n+1)/2;
	if(x >= k)
		x = k*2 - 1;
	else
		x = abs(k-x)*2; 
	cout<<x<<'\n';
	return 0;
}