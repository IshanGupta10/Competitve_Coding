#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	char v[8][8];
	
	char player;
	
	vector<int> Br;
	vector<int> Bc;
	vector<int> Wr;
	vector<int> Wc;
	
	for (int i = 0; i < 8; ++i)
	{
		for(int j = 0 ; j < 8; ++j)
		{
			cin>>player;
			v[i][j]=player;
		}
	}
	
	cout<<v[7][7];
	
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(v[i][j]=='B')
			{
				Br.push_back(i+1);
				Bc.push_back(j+1);
			}
			else if(v[i][j]=='W')
			{
				Wr.push_back(i+1);
				Wc.push_back(j+1);
			}
			else
				continue;
		}
	}
	
	 cout<<"Wr ";
	 for (int i = 0; i < 8; ++i)
	 {
	 	cout<<Wr[i]<<" ";
	 }
	 cout<<endl;
	 cout<<"Wc ";
	 for (int i = 0; i < 8; ++i)
	 {
	 	cout<<Wc[i]<<" ";
	 }
	 cout<<endl;
	 cout<<"Br ";
	 for (int i = 0; i < 8; ++i)
	 {
	 	cout<<Br[i]<<" ";
	 }
	 cout<<endl;
	 cout<<"Bc ";
	 for (int i = 0; i < 8; ++i)
	 {
	 	cout<<Bc[i]<<" ";
	 }
	 cout<<endl;
	
	for (int i = 0; i < 8; ++i)
	{
	  	if(Bc[i] == Wc[i])
	  	{
	  		Br.insert(Br.begin()+i,-1);
	  		Bc.insert(Bc.begin()+i,-1);
	  		Wr.insert(Wr.begin()+i,-1);
	  		Wc.insert(Wc.begin()+i,-1);
	  	}
	}

	int max_ = *max_element(Br.begin(),Br.end());
	int min_ = 8;
	
	for (int i = 0; i < 8; ++i)
	{

		if(Wr[i] == 0)
			continue;
		else if(Wr[i] < min_)
			min_ = Wr[i];
	}
	
	min_ = min_;
	max_ = 8 - max_;
	
	char res = (max_ > min_)? 'A' : 'B';
	
	cout<<res<<endl;
	
	return 0;
}
