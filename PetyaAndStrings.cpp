//http://codeforces.com/problemset/problem/112/A
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string a,b;
	int aux;
	cin>>a>>b;
	
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	transform(b.begin(), b.end(), b.begin(), ::tolower);
	
	for (int i = 0; i < a.size(); ++i)
		if (a[i]==b[i])
			aux = 0;
		else if(a[i] < b[i])
		{	
			aux = -1;
			break;
		}
		else if(a[i] > b[i])
		{	
			aux = 1;
			break;
		}
	cout<<aux<<'\n';
	return 0;
}