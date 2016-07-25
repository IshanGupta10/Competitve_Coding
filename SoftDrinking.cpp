//http://codeforces.com/problemset/problem/151/A
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n, k, l, c, d, p, nl, np;
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	
	int t1 = (k * l) / n, t2 = c * d, t3 = p / np;
	
//	cout<<t1<<" "<<t2<<" "<<t3<<'\n';
	
	cout<<min(t1, min(t2, t3)) / n;
	
	return 0;
}