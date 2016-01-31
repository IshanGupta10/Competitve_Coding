//http://codeforces.com/contest/606/problem/B

#include <iostream>

using namespace std;

bool used[501][501];

int main () 
{
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	int x, y, x0, y0;
	cin >> x >> y >> x0 >> y0;
	string s;
	cin >> s;
	int q = 0;

    for (int i = 0; i < s.size(); ++i) 
    {
    	if (!used[x0][y0]) 
    	{
            cout << 1 << " ";
            ++q;
        }
        else 
        	cout << 0 << " ";

        used[x0][y0] = true;
        
        if (s[i] == 'U') 
        	--x0;
        if (s[i] == 'D') 
        	++x0;
        if (s[i] == 'L') 
        	--y0;
        if (s[i] == 'R') 
        	++y0;
        if (x0 == 0) 
        	++x0;
        if (x0 == x + 1) 
        	--x0;
        if (y0 == 0) 
        	++y0;
        if (y0 == y + 1) 
        	--y0;
    }

    cout << x * y - q;
    return 0;
}