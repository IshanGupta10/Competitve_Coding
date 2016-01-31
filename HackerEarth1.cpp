//https://www.hackerearth.com/september-easy-15/algorithm/minimum-class/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int T,Q,aux;
	cin>>T;
	long int N;
	while( T > 0 )
	{
		cin>>N;
		Q = sqrt(N);
		aux = Q*Q;
		if(aux == N)
			cout<<2*Q-1<<'\n';
		else if(N <= aux+Q)
			cout<<2*Q<<'\n';
		else
			cout<<2*Q+1<<'\n';
		T--;
	}
	return 0;
}