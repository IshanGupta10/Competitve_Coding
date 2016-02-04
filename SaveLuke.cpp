// /http://codeforces.com/contest/624/problem/A
#include <iostream>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	double d, l , v1, v2, ans = 0;
	
	cin>>d>>l>>v1>>v2;
	
	ans = (l-d) / (v1+v2);
	
	if(l-d < 0)
		ans = 0;
	
	cout<<ans;
	return 0;
}