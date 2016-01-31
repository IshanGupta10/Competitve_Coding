#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &A) 
{
    vector<int>::iterator i;
    int carry = 0,flag=0;
    if(A.size()==1)
    	A.front() +=1;
    else if(A.size()>1 && A.back()!=0)
    {
    	for(i=A.end();i!=A.begin()-1;--i)
    	{
        	if(*i==9)
        	{
            	*i=0;
            	carry = 1;
        	}
        	else if((*i < 9 && *i>0) && carry==1)
        	{
            	*i = *i+carry;
            	carry=0;
            	break;
        	}
        	else if((*i<9 && *i>0) && carry==0)
        	{
            	*i += 1;
            	break;
        	}
        	else if(*i==0 && carry==1)
        	{
        		*i +=carry;
        		carry =0;
        		break;
        	}
    	}
    }
    else if(A.size()>1 && A.back()==0)
    {
    	A.back() += 1;
    }
    for(i=A.begin();i!=A.end();++i)
    {
        if(*i!=0)
            flag=1;
    }
	if(flag==0)
	{
		A.insert(A.begin(),carry);
	}
    for(i=A.begin();i!=A.end();++i)
    {    if(A.front()==0)
            A.erase(A.begin());
    }
    return A;
}
int main()
{
	vector<int> v,t;
	int n,q;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>q;
		v.push_back(q);
	}
	t=plusOne(v);
	for (vector<int>::iterator i = t.begin(); i != t.end(); ++i)
	{
		cout<<*i<<'\n';
	}
	return 0;
}