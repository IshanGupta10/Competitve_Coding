#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<string> s;
    string k, t;
    int n;
    
    cin>>n;
    
    for(int i = 0; i < n; ++i)
    {
        cin>>t;
        sort(t.begin(), t.end());
        s.push_back(t);
    }
    
    sort(s.begin(), s.end());
    
    for(int i = 0; i < n; ++i)
        k += s[i][0];
        
    cout<<k<<'\n';
    return 0;
}