#include <iostream>
#include <cstring>
using namespace std;

char a[2000000];
char b[2000000];


int main() 
{
	scanf(" %s", a);
	scanf(" %s", b);
	int na = strlen(a);
	int nb = strlen(b);
	char *a1 = a;
	char *b1 = b;
	while (na > 1 && a1[0] == '0') {
		++a1;
		--na;
	}
	while (nb > 1 && b1[0] == '0') {
		++b1;
		--nb;
	}
	if (na != nb) {
		if (na > nb)
			cout << ">";
		else
			cout << "<";
	}
	else {
		int x = strcmp(a1, b1);
		if (x == 0)
			cout << "=";
		else if (x < 0)
			cout << "<";
		else
			cout << ">";
	}
	return 0;
}