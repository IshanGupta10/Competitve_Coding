#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
void addBinary(string A, string B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	string s,q;
	vector<int> u,v;
	int a,power,dig1=0,dig2=0,j=0,sum,rem;
	for (int i = 0; i < A.length(); ++i)
	{
		a=A[i];
		u.push_back(a-48);
	}
	// cout<<"Vector u: ";
	// for (std::vector<int>::iterator i = u.begin(); i != u.end(); ++i)
	// {
	// 	cout<<*i<<" ";
	// }
	// cout<<endl;
	for (int i = 0; i < B.length(); ++i)
	{
		a=B[i];
		v.push_back(a-48);
	}
	//cout<<"Vector v: ";
	// for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	// {
	// 	cout<<*i<<" ";
	// }
	// cout<<endl;
	//	cout<<"for vector u: "<<endl;
	for (int i=u.size()-1;i>=0;i--)
	{
		power = pow(2,j);
		// cout<<"power "<<power<<endl;
		// cout<<"*i: "<<u[i]<<endl;
		dig1 += u[i] * power;
		// cout<<"dig1 "<<dig1<<endl;
		j++;
	}
	j=0;
	// cout<<"------------------ "<<endl;
	// cout<<"for vector v: "<<endl;
	for (int i=v.size()-1;i>=0;i--)
	{
		power = pow(2,j);
		// cout<<"power "<<power<<endl;
		// cout<<"*i: "<<v[i]<<endl;
		dig2 += v[i] * power;
		//cout<<"dig2 "<<dig2<<endl;
		j++;
	}
	cout<<dig1<<" "<<dig2<<endl;
	sum = dig1+dig2;
	cout<<sum<<endl;
	while(sum>1)
	{
		rem = sum%2;
		char value = ('0'+rem);
		cout<<"rem "<<rem<<endl;
		s.push_back(value);
		cout<<"sum "<<sum<<endl;
		sum = sum/2;
		if(sum==1)
		{
			char value = ('0'+sum);
			s.push_back(value);
		}
	}
	for (int i = s.length()-1; i >=0 ; --i)
	{
		q.push_back(s[i]);
	}
	//s.push_back('\0');
	for (int i = 0; i < q.length(); ++i)
	{
		cout<<q[i]<<" ";
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	string a = "1011";
	string b = "1111";
	addBinary(a,b);
	return 0;
}