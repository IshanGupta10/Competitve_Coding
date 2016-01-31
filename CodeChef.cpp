#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <limits.h>
#include <set>
#include <list>
using namespace std;
vector<int> printPascal(int n)
{
	vector<int> result;
	for (int line = 1; line <= n; line++)
	{
		int C = 1;  // used to represent C(line, i)
		for (int i = 1; i <= line; i++)
		{
			if (line == n)
				result.push_back(C);
			C = C * (line - i) / i;
		}		
	}
	return result;
}

int main()
{
	
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int n;
		cin >> n;
		vector<pair<int,int> > t;
		
		t.resize(n);
		
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			t[j] = make_pair(a, -1);
		}	
		t[0].second = 1;
		int team = 1;
		int ncount = 0;
		for (int i = 1; i < n; i++)
		{
			if (t[i].first == -1)
			{
				t[i].second = ++team;
				ncount++;
			}
			else
				t[i].second = t[t[i].first].second;
		}
		long long int sum = 0;
		vector<int> temp = printPascal(ncount + 1);
		
		long long int den = 0;
		for (int i = 0; i < temp.size(); i++)
		{
			sum += (team - i) * temp[i];
			den += temp[i];
		}
		float result = float(sum) / den;
		cout << result << endl;

	}

}