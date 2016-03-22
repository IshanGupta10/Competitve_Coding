//http://codeforces.com/problemset/problem/633/A
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c, flag = 0;
	cin>>a>>b>>c;

	for (int i = 0; i <= 10000; ++i)
		for (int j = 0; j <= 10000; ++j)
			if (i * a + j * b == c)
			{
				flag = 1;
				break;
			}

	if (flag)
		cout<<"Yes"<<'\n';
	else
		cout<<"No"<<'\n';
	return 0;
}