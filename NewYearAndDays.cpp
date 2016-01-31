//http://codeforces.com/contest/611/problem/0
#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int num;
    cin>>num;
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    if(s2[0]=='w')
    {
        if(num==6 || num ==5)
            cout<<53<<endl;
        else
            cout<<52<<endl;
    }
    if(s2[0]=='m')
    {
    if(num<=29)
        cout<<12<<endl;
    else if(num==30)
        cout<<11<<endl;
    else if(num==31)
        cout<<7<<endl;
    }
	return 0;
}