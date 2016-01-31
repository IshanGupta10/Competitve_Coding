#include <iostream>
#include <set>
using namespace std;

int main() 
{
	set<int> st;
	int n,num,q=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		st.insert(num);
	}
	for(set<int>::iterator i=st.begin();i!=st.end();i++)
	{
		if(q==2)
			break;
		else
		{
			num = *i;
			q++;
		}
	}
	if(st.size()==1)
		cout<<"NO"<<endl;	
	else
		cout<<num<<endl;
	return 0;
}