#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 200000

int main()
{
	ios_base::sync_with_stdio(false);
	set<char> str1;
	set<char> str2;
	set<char>::iterator it1;
	set<char>::iterator it2;
	char s[MAX],t[MAX];
	int i,j,count=0;
	cin>>s;
	cin>>t;
	for(i=0;i<strlen(s);i++)
		str1.insert(s[i]);

	for(i=0;i<strlen(t);i++)
		str2.insert(t[i]);

	//for(it1=str1.begin(),it2=str2.begin();it1!=str1.end(),it2!=str2.end();it1++,it2++)
	//	cout<<*it<<'\n';
	for(it1=str2.begin();it1!=str2.end();it1++)
	{
		/*
		it2=str1.find(*it1);
		if(*it1!=*it2)
		{
			cout<<"No";
			break;
		}
//		else
//			cout<<"Yes";
		*/
		if(binary_search(str1.begin(),str1.end(),*it1))
			count++;
	}

	//sort(str1.begin(),str1.end());
	//sort(str2.begin(),str2.end());

	/*
	for(j=0,i=0;j<str1.size(),i<str2.size();j++,i++)
	{
		if(str1[i]!=str2[j])
			cout<<"No";
		else
			cout<<"Yes";
	}
	*/
}