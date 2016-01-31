#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	long int x1,y1,x2,y2;
	while(T>0)
	{
		cin>>x1>>y1;
		cin>>x2>>y2;
		while(x1!=x2 && y1!=y2)
		{
			if(y2>x2)
				y1 = y1+x1;
			
		}
	}
	return 0;
}