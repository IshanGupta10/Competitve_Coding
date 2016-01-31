#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char p[1000000],q[1000000];
	scanf("%s",&p);
	scanf("%s",&q);
	int n = strlen(p);
	int m = strlen(q);
	
	char *a = p;
	char *b = q;
	
	while(n > 1 && a[0]=='0')
	{
		a++;
		n--;
	}
	while(m > 1 && b[0]=='0')
	{
		b++;
		m--;
	}
	
	if(n != m)
	{
		if(n > m)
			cout<<'>'<<'\n';
		else
			cout<<'<'<<'\n';
	}
	else
	{
		int x = strcmp(a,b);
		if(x > 0)
			cout<<'>'<<'\n';
		else if(x == 0)
			cout<<'='<<'\n';
		else
			cout<<'<'<<'\n';
	}
	return 0;
}