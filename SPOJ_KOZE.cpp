#include <bits/stdc++.h>
using namespace std;

vector<char> c;
vector<vector<char> > v;
int visited[251][251] = {0};
int s, w;


void dfs(int i, int j, int n, int m)
{
	visited[i][j] = 1;

	if(v[i][j] == 'k')
		s++;
	if(v[i][j] == 'v')
		w++;

	if(i + 1 < n && !visited[i + 1][j])
		if(v[i + 1][j] == 'k' || v[i + 1][j] == 'v' || v[i + 1][j] == '.')
			dfs(i + 1, j, n, m);

	if(i - 1 >= 0 && !visited[i - 1][j])
		if(v[i - 1][j] == 'k' || v[i - 1][j] == 'v' || v[i - 1][j] == '.')
			dfs(i - 1, j, n, m);

	if(j + 1 < m && !visited[i][j + 1])
		if(v[i][j + 1] == 'k' || v[i][j + 1] == 'v' || v[i][j + 1] == '.')
			dfs(i, j + 1, n, m);

	if(j - 1 >= 0 && !visited[i][j - 1])
		if(v[i][j - 1] == 'k' || v[i][j - 1] == 'v' || v[i][j - 1] == '.')
			dfs(i, j - 1, n, m);

}


int main(int argc, char const *argv[])
{
	int n, m, tots = 0, totw = 0;
	char t;
	cin>>n>>m;

	for (int i = 0; i < n; ++i)
	{
		v.push_back(c);
		for (int j = 0; j < m; ++j)
		{
			cin>>t;
			v[i].push_back(t);
		}
	}
	

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			s = 0;
			w = 0;
			if(!visited[i][j])
				dfs(i, j, n, m);
		// cout<<"w "<<w<<" s "<<s<<'\n';
			if(w > s || w == s)
				totw += w;
			if(s > w)
				tots += s;
		}
	}

	cout<<tots<<" "<<totw<<'\n';
	return 0;
}