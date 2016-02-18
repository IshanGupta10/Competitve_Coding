//http://codeforces.com/contest/630/problem/N
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() 
{
	long double a, b, c, root1, root2, val;
	cin>>a>>b>>c;

	root1 = ((-1 * b) + sqrt(pow(b,2) - (4 * a * c))) / (2 * a);
	root2 = ((-1 * b) - sqrt(pow(b,2) - (4 * a * c))) / (2 * a);
	
	if(root1 >= root2)
	{
		cout<<fixed<<setprecision(14)<<root1<<'\n';
		cout<<fixed<<setprecision(14)<<root2<<'\n';
	}
	else
	{
		cout<<fixed<<setprecision(14)<<root2<<'\n';
		cout<<fixed<<setprecision(14)<<root1<<'\n';
	}
	return 0;
}