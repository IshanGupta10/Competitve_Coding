// https://csacademy.com/contest/archive/#task/neighbour-sum-replacement/
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<int> v, x;
    int n, t;
    
    cin>>n;
    
    for(int  i = 0; i < n; ++i)
    {
        cin>>t;
        v.push_back(t);
    }
    
    x = v;
    
    for(int i = 1; i < n - 1; ++i)
        v[i] = x[i - 1] + x[i + 1];
    
    v[0] = x[n - 1] + x[1];
    v[n - 1] = x[n - 2] + x[0];
    
    for(auto i : v)
        cout<<i<<" ";
}