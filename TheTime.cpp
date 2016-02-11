//http://codeforces.com/contest/622/problem/B
#include <iostream>
using namespace  std;

int main(int argc, char const *argv[])
{
    int h, m, x;
    string k;
    
    cin>>k;
    cin>>x;
    
    h = 10 * (k[0]-'0') + (k[1] - '0');
    m = 10 * (k[3]-'0') + (k[4] - '0');
    
    while(x--)
    {
        m++;
        if(m == 60)
        {
            m = 0;
            h++;
            if(h == 24)
                h = 0;
        }
    }
    
    printf("%02d:%02d",h,m); 
    return 0;
}