//http://codeforces.com/contest/624/problem/B
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin>>N;
    long long arr[N];

    for(int i=0;i<N;i++)
        cin>>arr[i];

    sort(arr,arr+N);

    for(int i = N-1; i >= 1; i--)
    {
        if(arr[i] <= arr[i-1])
        {
            if((arr[i]-1) < 0)
        	    arr[i-1] = 0;
            else
            	arr[i-1] = arr[i]-1;
        }
    }
    long long ans =0 ;
    for(int i = 0; i < N; i++)
        ans = ans + arr[i];
    cout<<ans<<endl;
    return 0;
}