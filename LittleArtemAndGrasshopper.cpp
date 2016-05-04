#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int len[200005], n;
	bool visited[200005] = {false};

	cin>>n;
	cin>>s;
	
	for (int i = 0; i < n; i++)
		cin>>len[i];

	for (int t = 0; visited[t] == false;)
	{
		visited[t] = true;
		t = t + len[t] * (s[t] == '<' ? -1 : 1);
		if (t < 0 || t >= n)
		{
			cout<<"FINITE"<<'\n';
			return 0;
		}
	}
	cout<<"INFINITE"<<'\n';
	return 0;
}