#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin>>a>>b>>c;

	if(a == b) { cout << "YES\n"; return 0; }
	if(a < b) {
		if(c <= 0) cout << "NO\n";
		else {
			if((b - a) % c == 0) cout << "YES\n";
			else cout << "NO\n";
		}
		return 0;
	}
	if(a > b) {
		if(c >= 0) cout << "NO\n";
		else {
			if((a - b) % -c == 0) cout << "YES\n";
			else cout << "NO\n";
		}
		return 0;
	}
	return 0;
}