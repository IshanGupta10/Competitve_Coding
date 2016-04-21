//
#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long int> v, x;

bool isPrime(unsigned long long int n)
{
    if (n == 2)
        return true;
    if (n == 3)
        return true;
    if (n % 2 == 0)
        return false;
    if (n % 3 == 0)
        return false;
    
    unsigned long long int i = 5;
    unsigned long long int w = 2;

    while (i * i <= n)
    {
        if (n % i == 0)
            return false;
        i += w;
        w = 6 - w;
    }

    return true;
}

void init()
{
    for(int i = 2; i <= 400000; ++i)
        if(isPrime(i))
            v.push_back(i);

    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = i + 1; j < v.size(); ++j)
        {
            x.push_back(v[i]*v[j]);
        }
    }
}

int main() 
{
    init();
    unsigned long long int n, count = 0;
    cin>>n;

    for (int i = 0; i < x.size(); ++i)
        if (x[i] <= n)
            count++;

    for (int i = 0; i < v.size(); ++i)
    {
         cout<<v[i]<<" ";
    }
    cout<<'\n'<<"Size of vector v "<<v.size()<<'\n';

    for (unsigned long long int i = 0; i < x.size(); ++i)
    {
         cout<<x[i]<<" ";
    }
    cout<<'\n'<<"Size of vector x "<<x.size()<<'\n';
    
    cout<<"count "<<count<<'\n';
    return 0;
}