//http://codeforces.com/contest/626/problem/C
#include <iostream>
using namespace std;

int main() 
{
	int n, m, a, b, count;
	cin>>n>>m;
	
	a = 2 * n;
	b = 3 * m;
	count = a / 6;
	int m1 = max(a + 2 * count , b);
	int m2 = max(a , b + 3 * count);
	cout<<min(m1,m2);
	return 0;
}