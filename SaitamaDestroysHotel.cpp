//http://codeforces.com/contest/608/problem/A
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, s, f, t;
  	cin >> n >> s;
  
  	int ans=s;
  	for (int i=0; i<n; ++i)
  	{
    	cin >> f >> t;
    	ans = max(ans, f+t);
  	}
  	cout << ans << '\n';
}