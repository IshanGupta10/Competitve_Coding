#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int k,n,w;
	cin>>k>>n>>w;
	int diff=0;
	int total = k*(w*(w+1))/2;
	diff = total - n;
	if(diff < 0)
		cout<<0<<endl;
	else
		cout<<diff<<endl;
	return 0;
}