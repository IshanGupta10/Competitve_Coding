#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <memory.h>
#include <ctime>
#include <set>
#include <map>
#include <math.h>
#include <queue>
#include <bitset>
#define ll long long
 
using namespace std;

const int maxn = (int)1e5 + 10;

pair <long long, long long> y[maxn];

int main() {
	int n;

	cin >> n;

	ll x1, x2;

	cin >> x1 >> x2;

	for (int i = 0; i < n; i++) {
		long long k, b;

		cin >> k >> b;

		y[i] = make_pair(x1 * k + b, x2 * k + b);
	}

	sort(y, y + n);

	for (int i = 0; i < n - 1; i++) {
		if (y[i].first < y[i + 1].first && y[i].second > y[i + 1].second) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}
