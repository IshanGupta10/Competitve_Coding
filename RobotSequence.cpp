//http://codeforces.com/contest/626/problem/A
#include <iostream>
using namespace std;

int main()
{
    int n , ans = 0;
    cin>>n;
    string s;
    cin>>s;

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int sum = 0, sum1 = 0;
            for(int k = i; k <= j; k++)
            {
                if(s[k] == 'U')
                    sum++;
                if(s[k] == 'L')
                    sum1++;
                if(s[k] == 'D')
                    sum--;
                if(s[k] == 'R')
                    sum1--;
            }
            if(sum == 0 && sum1 == 0)
            {
              ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}