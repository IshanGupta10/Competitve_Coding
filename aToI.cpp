#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

int atoi(const string &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i=0,flag=0,space=0,q=0;
    vector<int> v;
    long long int num,sum=0;
    for(string::const_iterator i=A.begin(); i!=A.end();i++ )
    {
        if(*i=='-')
        {
            flag=1;
            if(*(i+1)==' ')
                return 0;
            continue;
        }
        if(*i=='+')
        {
            //flag=1;
            if(*(i+1)==' ')
                return 0;
            continue;
        }        
        if(*i==' ')
        {
            if(space==1)
                break;
            // if(space==0)
            // {
            //     space=1;
            //     continue;
            // }
            // else
            //     break;
            continue;
            if(*(i+1)<=48 && *(i+1)<=57)
                space=1;
        }
        num = *i;
        if(num>INT_MAX)
            return INT_MAX;
        if(num<48 || num>57)
        {
            if(i==A.begin())
               return 0;
            else
                break;
        }
        //cout<<"NUM "<<num<<endl;
        if(num>=48 && num<=57)
        {
            num = num-48;
            v.push_back(num);
        }
        //cout<<"num "<<num<<endl;
        if(*(i+1)==' ')
            break;
        // if(*(i+1)<48 && *(i+1)>57)
        //     break;
    }
    // for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    // {
    //     cout<<*i;
    // }
    //cout<<endl;
    for(i=v.size()-1;i>=0;i--)
    {
        sum = sum + (v[i]*pow(10,q));
        if(flag==1 && sum>=INT_MAX)
            return INT_MIN;
        else if(flag==0 && sum>=INT_MAX)
            return INT_MAX;
        //cout<<"sum "<<sum<<endl;
        q++;
    }
    if(flag==1)
        return -1*sum;
    else
        return sum;
    // if(sum>=0)
    // {
    //     if(sum>=INT_MAX)
    //         return INT_MAX;
    //     else
    //         return sum;
    // }
    // if(sum<0)
    // {
    //     if(sum<=INT_MIN)
    //         return INT_MIN;
    //     else
    //         return sum;
    // }
}

int main(int argc, char const *argv[])
{
    string k=" 7 U 0 T7165  0128862 089 39 5";
    int x = atoi(k);
    cout<<x<<endl;
    return 0;
}