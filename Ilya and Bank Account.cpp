// http://codeforces.com/problemset/problem/313/A
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int num,rem,divi,a[2];
	cin>>num;
	if( num >= 0)
		cout<<num<<'\n';
	else
	{
		divi = abs(num) / 100;
		rem = abs(num) % 100;
		a[0] = rem % 10;
		a[1] = rem / 10;
		if (a[1] >= a[0])
		{
			rem = (divi*10)+a[0];
			cout<<-1*rem<<'\n';
		}
		else
		{
			rem = (divi*10)+a[1];
			cout<<-1*rem<<'\n';			
		}
	}
	return 0;
}