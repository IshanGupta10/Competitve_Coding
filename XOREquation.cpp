//http://codeforces.com/contest/635/problem/C
#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long int ulli;
vector<int> q;
 
void ConvertToBinary(ulli n)
{
     if (n / 2 != 0) {
         ConvertToBinary(n / 2);
     }
     q.push_back(n%2);
}
 
 
int main() 
{
//	pair<ulli,ulli> p;
	vector<pair<ulli,ulli>> v;
	ulli s, t, ans = 0;
	cin>>s>>t;
	ConvertToBinary(t);
	ulli count = pow(2,q.size());
//	cout<<count<<'\n';
	// for(auto i:q)
	// 	cout<<i<<" ";
	// cout<<endl;
	for(ulli i = 1; i < count/2; ++i)
	{
	 	if((i ^ (s - i)) == t && i < s)
	 		ans++;
			// v.push_back(make_pair(i,j));
	}
	cout<<ans * 2;
	return 0;
}