#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	int a[4], min, max;
	for (int i = 0; i < 4; ++i)
	{	
		cin>>s;
		a[i] = s.size()-2; 
	}
	sort(a,a+4);
	int k = a[0]*2;
	int q = a[3]/2;
	for (int i = 1; i < 4; ++i)
		if(k <= a[i])
			flag=1;
	return 0;
}