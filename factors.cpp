#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isPower(int x);
};
int gcd(int a,int b)
{
    if(a==0)
        return a;
    if(a%b == 0)
        return 1;
    gcd(b,a%b);
    // if(a>b)
    //     return gcd(a,a-b)
    // else
    //     return gcd(b-a,b);
}
bool Solution::isPower(int A) 
{
    if (A==0 || A==1)
        return 1;
    int count=0;    
    vector<int> factors;
    vector<bool> prime;
    for (int i=0;i<A;i++)
        prime.push_back(true);
    for (int i=2;i<A;i++)
    {
        if (!prime[i])
            continue;
        for (int j = i*i;j<A;j+=i)
            prime[j] = false;
    }
    for (std::vector<bool>::iterator i = prime.begin(); i != prime.end(); ++i)
    {
        cout<<"Prime Number "<<*i<<endl;
    }
    int aux=0;
    for(int i=2;i*i<=A;i++)
    {
        if (!prime[i])
            continue;
        int num=A;
        while(A>0)
        {
            if(A%i == 0)
            {
                A=A/i;
                count++;
            }
            else
            break;
        }
        if(count==1)
            return 0;
        factors.push_back(count);
        count=0;
    }
    int q = *min_element(factors.begin(),factors.end());

    for (std::vector<int>::iterator i = factors.begin(); i != factors.end(); ++i)
    {
        if(gcd(*i,q) == 0)
            return 0;
        cout<<"Factors "<<*i<<endl;
    }    
    return 1;
}
int main()
{
    Solution A;
    int n;
    cin>>n;
    if(A.isPower(n))
        cout<<1;
    else
        cout<<0;
    return 0;
}