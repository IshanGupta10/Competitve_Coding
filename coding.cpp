#include <iostream>

using namespace std;

int main()
{
	for(int i=1;i<=9;i++)
	{
		if(i==4)
			cout<<9;
		else if(i==5)
			cout<<8;
		else if(i==6)
			cout<<4;
		else if(i==7)
			cout<<5;
		else if(i==8)
			cout<<7;
		else if(i==9)
			cout<<6;
		else
			cout<<i;
		cout<<'\n';
	}	
return 0;
}