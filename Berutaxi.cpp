// http://codeforces.com/problemset/problem/706/A
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	double a, b, x, y, t, ans = 0;
	int n;
	vector<double> tim;

	cin>>a>>b;
	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y>>t;

		ans = sqrt(pow((a - x), 2) + pow((b - y), 2));

		tim.push_back(ans / t);
	}

	ans = *min_element(tim.begin(), tim.end());

	cout<<setprecision(12)<<ans<<'\n';

	return 0;
}
