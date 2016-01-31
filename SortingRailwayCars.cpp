//http://codeforces.com/contest/606/problem/C
#include <bits/stdc++.h>

using namespace std;

bool used[501][501];

int main () 
{

    int n;
    cin >> n;
    int a[n], b[n];

    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i];
        --a[i];
        b[a[i]] = i;
    }

    int ans = 0;

    int q = 1;

    for (int i = 1; i < n; ++i) 
    {

        if (b[i] > b[i - 1]) 
            ++q;
        else 
        {
            if (q > ans) 
                ans = q;
            q = 1;
        }
    }
    if (q > ans) 
        ans = q;
    cout << n - ans;
    return 0;
}