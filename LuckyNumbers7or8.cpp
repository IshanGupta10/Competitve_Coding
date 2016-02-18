//http://codeforces.com/contest/630/problem/C
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int ulli;

vector<ulli> v;

ulli init(int n)
{
	ulli ans = 1;
	
	for(int i = 0; i < 55; ++i)
	{
		ans *= 2;
		v.push_back(ans);
	}
	//return v[54];
	ulli sum = 0;

	for(int i = 0; i < n; ++i)
	 	sum+=v[i];

	return sum;
}

int main() 
{
	int n;
	cin>>n;
	cout<<init(n)<<'\n';
	return 0;
}