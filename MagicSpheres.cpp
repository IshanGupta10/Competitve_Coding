#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(false);

	int a,b,c,x,y,z,pos,neg;
	cin>>a>>b>>c>>x>>y>>z;

	pos = max(a-x,0)/2 + max(b-y,0)/2 + max(c-z,0)/2;
	neg = max(x-a,0) + max(y-b,0) + max(z-c,0);

	if(pos >= neg)
		cout<<"Yes"<<'\n';
	else
		cout<<"No"<<'\n';
	return 0;
}