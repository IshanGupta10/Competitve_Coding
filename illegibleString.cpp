#include <iostream>
#include <string>
using namespace std;

int getMax(string &a)
{
    string s1 = "";
    for(i=0;i<n;i++)
    {
    	if(a[i]=='w')
    	{
    		s1+="vv";
    	}
    	else
    	{
    		s1+=a[i];
    	}
    }
	return s1.size();
}

int getMin(string &a)
{
	int count=0,v=0,quo=0,rem=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]=='v')
			v++;
		else
			count++;
	}
	quo = v/2;
	rem = v%2;
	return count+quo+rem;	
}

int main()
{
	int N;
	cin>>N;
	string s;
	char a;
	for(int i = 0;i < N; i++)
	{
		cin>>a;
		s.push_back(a);
	}
	int _min = getMin(s);
	int _max = getMax(s);
	cout<<_min<<" "<<_max;
    return 0;
}
