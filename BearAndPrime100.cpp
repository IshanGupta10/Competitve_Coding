// http://codeforces.com/contest/680/problem/C
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int	a[] = {2,4,3,5,7,9,11,13,17,19,23,25,29,31,37,41,43,47,49,53,59,61,67,71,73,79,83,89,97};

int main(int argc, char const *argv[])
 {
 	string s;
 	int i = 0, nocount = 0, yescount = 0;

 	while(i < 20)
 	{
 		cout<<a[i]<<endl;
 		fflush(stdout);
 		
 		cin>>s;

 		if(!s.compare("yes"))
 			yescount++;

 		i++;
 	}
 	if(yescount <= 1)
 	{	
 		cout<<"prime"<<'\n';
		fflush(stdout);
	}
	else
	{	
 		cout<<"composite"<<'\n';
		fflush(stdout);
	}
 	return 0;
 } 