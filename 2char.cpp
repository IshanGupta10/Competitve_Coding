#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
string s[100];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) 
		cin >> s[i];

	int best = 0;
	for(int a = 'a'; a <= 'z'; a++)
		for(int b = a + 1; b <= 'z'; b++)
		{
			int cur = 0;
			for(int k = 0; k < n; k++)
			{
				int cnt = 0;
				for(int i = 0; i < s[k].size(); i++)
					if (s[k][i] == a || s[k][i] == b) 
						cnt++; 
					else 
					{ 
						cnt = 0; 
						break; 
					}
				cur += cnt;
			}
			best = max(best, cur);
		}
	cout << best << endl;
	return 0;
}