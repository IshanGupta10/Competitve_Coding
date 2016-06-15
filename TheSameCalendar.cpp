// http://codeforces.com/contest/678/problem/B
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

ulli leap(ulli y) 
{
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}


int main(int argc, char const *argv[])
{
	ulli n, val, x = 0, ans = 0;
	cin>>n;

	val = leap(n);
    for (ulli i = n; 1; i++) 
    {
        x = (x + 365 + leap(i)) % 7;
        if (leap(i + 1) == val && x == 0) 
        {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}