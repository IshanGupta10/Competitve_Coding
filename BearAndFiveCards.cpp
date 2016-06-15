// http://codeforces.com/contest/680/problem/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[5];
    int freq[101];
    memset(freq,0,sizeof(freq));
    int ans =0;

    for(int i = 0; i < 5; i++)
    {
        cin>>a[i];
        ans += a[i];
        freq[a[i]]++;
    }

    int sum = 0;

    for(int i = 1; i <= 100; i++)
    {
        if(freq[i] >= 3)
        	freq[i] = 3;
        if(freq[i] == 2 || freq[i] == 3)
            sum = max(sum,freq[i]*i);
    }
    ans -= sum;
    cout<<ans;
    return 0;
}