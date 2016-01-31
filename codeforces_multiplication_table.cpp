#include "bits/stdc++.h"
using namespace std;

// typedef long long int lli;
// typedef unsigned long long int ulli;

// bool isPrime(ulli num) 
// {
//     if (num <= 3)
//         return num > 1;
//     else if (num % 2 == 0 || num % 3 == 0)
//         return false;
//     else 
//     {
//         for (ulli i = 5; i * i <= num; i += 6)
//             if (num % i == 0 || num % (i + 2) == 0)
//                 return false;
//         return true;
//     }
// }
// vector<int> findDivisor(int num)
// {
// 	vector<int> v;
// 	int square_root = (int) sqrt(num) + 1;
// 	for (int i = 1; i < square_root; i++)
// 		if (num % i == 0)
// 		{
//     		v.push_back(i);
//     		v.push_back(num/i);
// 		}
// 	sort(v.begin(),v.end());
// 	return v;
// }
int main(int argc, char const *argv[])
{
	int n,x,count=0;
	cin>>n>>x;
	for (int i = 1; i <= n; ++i)
		if(x%i==0 && x/i<=n)
			count++;
	cout<<count<<endl;
	return 0;
}