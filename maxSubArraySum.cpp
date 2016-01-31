#include <iostream>
#include <vector>
using namespace std;

int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int maxSubArray(const vector<int> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int>::const_iterator i;
    i=A.begin();
    int max1=*i,max2=0;
    for(i=A.begin();i != A.end();++i)
    {   /*
        max2 = max(*i,max2+(*i));
        max1 = max(max1,max2);
        /*
        max2=max2+*i;
        if(max2 < 0)
            max2=0;
        if(max1 < max2)
            max1 = max2;
            */
        max2 = max2 + *i;
        if (max1 < max2)
        max1 = max2;
        //printf("%d %d\n",max1,max2);
        if(max2 < 0)
        max2 = 0;
    }
    return max1;
}


int main()
{
    int i=0,n,t;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        cin>>t;
        v.push_back(t);
    }
    t=maxSubArray(v);
    cout<<"Ola "<<t;
}