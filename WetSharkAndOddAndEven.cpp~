//http://codeforces.com/contest/621/problem/A
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

int main()
{
    int N;
    cin>>N;
    ulli num;
    ulli ans=0;
    int min_odd=1000000005;
    for(int i=0;i<N;i++){
        cin>>num;
        ans+=num;
        if(num%2)
        {
            if(num<min_odd)
                min_odd=num;
        }
    }
    if(ans%2)
            ans-=min_odd;
      cout<<ans;
    return 0;
}