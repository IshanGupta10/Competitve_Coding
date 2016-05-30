#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string a, b, c;

	cin>>a;

	for (int i = 0; i < a.size(); ++i)
	{
		if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || 
								a[i] == 'o' || a[i] == 'u' || a[i] == 'y')
			b += a[i];
		else
			c += a[i];
	}
	
	if(b.compare(c) >= 0)
		cout<<"Vowel";
	else
		cout<<"Consonant";
	
	return 0;
}