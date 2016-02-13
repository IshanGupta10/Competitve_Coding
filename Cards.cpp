//http://codeforces.com/contest/626/problem/B
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cr = 0, cb = 0, cg = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(s[i]=='R')
            cr++;
        if(s[i]=='B')
            cb++;
        if(s[i]=='G')
            cg++;
    }

    if((cb > 0 && cr > 0 && cg > 0) || (cr > 1 && cg > 1) || (cb > 1 && cg > 1) ||(cr > 1 && cb > 1))
        cout<<"BGR";
    if(cb == 0)
    {
	    if(cr > 1 && cg == 1)
    		cout<<"BG";
    	if(cr == 1 && cg > 1)
    		cout<<"BR";
    }
	if(cr == 0)
    {
        if(cb > 1 && cg == 1)
        	cout<<"GR";
        if(cb == 1 && cg > 1)
	        cout<<"BR";
    }
    if(cg == 0)
    {
    	if(cr > 1 && cb == 1)
    		cout<<"BG";
    	if(cr == 1 && cb > 1)
    		cout<<"GR";
    }
    if((cb == 0 && cr == 1 && cg == 1) || (cr == 0 && cg == 0 && cb > 0))
        cout<<"B";
    if((cr == 0 && cb == 1 && cg == 1) ||(cb == 0 && cg == 0 && cr > 0))
        cout<<"R";
    if((cg == 0 && cb == 1 && cr == 1) ||(cb == 0 && cr == 0 && cg > 0))
        cout<<"G";
    return 0;
}