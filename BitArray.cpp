//https://www.hackerrank.com/contests/code-cpp-3/challenges/bitset-1
#include <iostream>
#include <map>
#include <climits>
using namespace std;
typedef unsigned long long int ulli;
int main() 
{
    int N, S, P, Q, count = 0;
    map<ulli,int> st;
    cin>>N>>S>>P>>Q;
    ulli a[N];
    a[0] = S%INT_MAX;
    for(int i = 1; i < N; ++i)
        a[i] = a[i-1] * P + Q % INT_MAX;
    for(int  i = 0; i < N; ++i)
        if(st.find(a[i])!=st.end())
            st[a[i]]++;
        else
            st[a[i]] = 1;
    for(auto i:st)
        if(i.second == 1)
            count++;
    cout<<count;
    return 0;
}
