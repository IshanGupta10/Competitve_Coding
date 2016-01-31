//http://codeforces.com/contest/615/problem/D
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

typedef unsigned long long int ulli;
#define MOD 1000000007

int main() 
{
	ulli n, m, fact = 1, ans = 1;
	vector<ulli> st;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		fact *= m;
	}
	
	//cout<<fact;
	
	ulli square_root = (ulli) sqrt(fact) + 1;
	
	for (int i = 1; i < square_root; i++)
	{ 
		if (fact % i == 0)
		{
			st.push_back(i);
			st.push_back(fact/i);
		}
	}
	
	sort(st.begin(),st.end());
	
	for(auto i =st.begin();i!=st.end();i++)
	{
		if(ans * *i > ULLONG_MAX)
			break;
		else
		{
			ans  = (ans%MOD * *i%MOD) % MOD;
			//ans%=MOD;
			//cout<<"ans "<<ans<<'\n';
		}
	}
	
	cout<<ans<<'\n';
	return 0;
}