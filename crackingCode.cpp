/********* Codechef problem =  CODECRCK *********/ 

#include <iostream>
#include <cmath>
#include <cstdio>
//#include <vector>
using namespace std;

typedef long long int ll;

// vector<int> calculateAk(int a, int b, int i, int k)
// {
// 	float x = sqrt(2);
// 	float y = sqrt(3);
// 	float ak,bk;
// 	vector<int> q;
// 	for (int j = i; j <= k; ++j)
// 	{
// 		ak = x*(a + b) - (x*y*(a - b));
// 		bk = x*(a - b) + (x*y*(a + b));
// 		a = ak;
// 		b = bk;
// 	}
// 	cout<<ak<<" "<<bk<<endl;
// 	q.push_back(ak);
// 	q.push_back(bk);
// 	return q;
// }

int main(int argc, char const *argv[])
{
	int i,k,s;
	ll a_i,b_i;
	double a_k,b_k,Q;
	cin>>i>>k>>s;
	cin>>a_i>>b_i;
	//vector<int> v;
	if (k&1 != i&1)
	{
	 		a_k = sqrt(2.0)*((a_i + b_i) - sqrt(3.0)*(a_i - b_i));
	 		b_k = sqrt(2.0)*((a_i - b_i) + sqrt(3.0)*(a_i + b_i));
	 		a_i = a_k;
	 		b_i = b_k;
	 		i++;
	 }
		// v.push_back(a_i);
		// v.push_back(b_i);
	//	cout<<v[0]<<" "<<v[1]<<endl;
	//Q = (a_i+b_i)*pow(2.0,(2*(k-i))-s);
	// else
	// 	v = calculateAk(a_i,b_i,i,k);
	// cout<<v[0]<<" "<<v[1]<<endl;
	// //b_k = calculateBk(a_i,b_i,i,k);
	// float Q = (v[0] + v[1]) / pow(2,s);
	printf("%0.10f",(a_i + b_i) * pow(2.0, ((k - i) << 1) - s));
	return 0;
}