#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

bool checkDigit(char *A,char *B)
{
	int num,minus=0,plus=0,i=0,dot=0;
	vector<bool> v;
	while(*(A+i) != *B)
	{
		if(*(A+i)=='.' && i==0)
			return false;
		if(*(A+i)=='.' && dot>2)
			return false;
		if(*(A+i)=='-' && minus>2)
			return false;
		if(*(A+i)=='+' && plus>2)
			return false;
		if(*(A+i)=='-' && *(A+i+1)=='.')
			return false;
		if(*(A+i)=='+' && *(A+i+1)=='.')
			return false;
		if(*(A+i)=='-')
			minus++;
		if(*(A+i)=='+')
			plus++;
		if(*(A+i)=='.')
			dot++;
		if(*(A+i)>=48 && *(A+i)<=57)
			v.push_back(true);
		else
			v.push_back(false);
		cout<<"Value "<<*(A+i)<<endl;
		i++;
	}
	cout<<"--------------------------------"<<endl;
	for (vector<bool>::iterator i = v.begin(); i != v.end(); ++i)
	{
		if(*i==false)
			return false;
	}
	return true;
}
int validNumber(string &A)
{
	bool a,b;
	int plus=0,minus=0,dot=0;
	for (int i = 0; i < A.size(); ++i)
	{
		if(A[i]=='.' && i==0)
			return false;
		if(A[i]=='.' && dot>2)
			return false;
		if(A[i]=='-' && minus>2)
			return false;
		if(A[i]=='+' && plus>2)
			return false;
		if(A[i]=='-' && A[i+1]=='.')
			return false;
		if(A[i]=='+' && A[i+1]=='.')
			return false;
		if(A[i]=='-')
		{
			minus++;
			continue;
		}
		cout<<"minus "<<minus<<endl;
		if(A[i]=='+')
		{
			plus++;
			continue;
		}
		cout<<"plus "<<plus<<endl;		
		if(A[i]=='.')
		{
			dot++;
			continue;
		}
		cout<<"dot "<<dot<<endl;
		if(A[i]=='e')
		{
			cout<<"Checking a ------------------"<<endl;
			a=checkDigit(&A[0],&A[i-1]);
			cout<<"a "<<a<<endl;
			cout<<"Checking b ------------------"<<endl;
			b=checkDigit(&A[i+1],&A[A.length()-1]);
			cout<<"b "<<b<<endl;
			if(a==true && b==true)
				return true;
			else
				return false;
		}
		cout<<"Hi "<<endl;
		if(A[i]==' ')
			return false;
		cout<<"Hello "<<endl;
		if(A[i]=='-' && A[i+1]=='.')
			return false;
		cout<<"Mello "<<endl;
		if(A[i]=='-' && (A[i+1]>57 || A[i+1] <47))
			return false;
		cout<<"Jello "<<endl;
		if(A[i]=='+' && (A[i+1]>57 || A[i+1] <47))
			return false;
		cout<<"Fello "<<endl;
		if(A[i]=='.' && (A[i+1]>57 || A[i+1] <47))
			return false;
		cout<<"Cello "<<endl;		
		if(A[i]=='+' && A[i+1]=='.')
			return false;
		cout<<"Wello "<<endl;
		if(A[i]>57 || A[i]<47)
			return false;
		cout<<"Xello "<<endl;
		cout<<"A[i] "<<A[i]<<endl;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	string k="123.12e0.98";
	if(validNumber(k))
		cout<<1;
	else
		cout<<0;
	return 0;
}