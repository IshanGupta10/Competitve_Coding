#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
 {
 	string s, k;
 	cin>>s;

 	if(s[0] == 'X')
 	{
 		int val = 1;
 		k += char(val + 48);
 		for (int i = 0; i < s.size(); ++i)
 		{
 			if(s[i] == 'X')
 			{
 				val++;
	 	 		k += char(val + 48);
 			}
 			else
 			{
 				val--;
		 		k += char(val + 48);
 			}
 		}
 	}
 	else
 	{
 	 	int count = 1;
 	 	for (int i = 0; i < s.size(); ++i)
 	 	{
 	 		if(s[i] == 'X')
 	 			break;
 	 		count++;
 	 	}
 	 	k += char(count + 48);
 	 	for (int i = 0; i < s.size(); ++i)
 		{
 			if(s[i] == 'X')
 			{
 				count++;
	 	 		k += char(count + 48);
 			}
 			else
 			{
 				count--;
		 		k += char(count + 48);
 			}
 		}
 	}
 	cout<<k<<'\n';
 	return 0;
 } 