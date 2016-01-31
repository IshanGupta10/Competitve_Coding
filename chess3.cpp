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
	
	int Br[8] = {0};
	int Bc[8] = {0};
	int Wr[8] = {0};
	int Wc[8] = {0};
	
	for (int i = 0; i < 8; ++i)
	{
		for(int j = 0 ; j < 8; ++j)
		{
			cin>>player;
			v[i][j]=player;
		}
	}
	
	int q=0,r=0;

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(v[i][j]=='B')
			{
				Br[q] = i+1;
				Bc[q] = j+1;
				q++;
			}
			else if(v[i][j]=='W')
			{
				Wr[r] = i+1;
				Wc[r] = j+1;
				r++;
			}
			else
				continue;
		}
	}
	
	  // cout<<"Wr ";
	  // for (int i = 0; i < 8; ++i)
	  // {
	  // 	cout<<Wr[i]<<" ";
	  // }
	  // cout<<endl;
	  // cout<<"Wc ";
	  // for (int i = 0; i < 8; ++i)
	  // {
	  // 	cout<<Wc[i]<<" ";
	  // }
	  // cout<<endl;
	  // cout<<"Br ";
	  // for (int i = 0; i < 8; ++i)
	  // {
	  // 	cout<<Br[i]<<" ";
	  // }
	  // cout<<endl;
	  // cout<<"Bc ";
	  // for (int i = 0; i < 8; ++i)
	  // {
	  // 	cout<<Bc[i]<<" ";
	  // }
	  // cout<<endl;
	
	for (int i = 0; i < 8; ++i)
	{
	  	if(Bc[i] == Wc[i])
	  	{
	  		Br[i] = -1;
	  		Bc[i] = -1;
	  		Wr[i] = -1;
	  		Wc[i] = -1;
	  	}
	}

	int max_ = 0;

	for (int i = 0; i < 8; ++i)
	{

		if(Br[i] == -1)
			continue;
		else if(Br[i] > max_)
			max_ = Br[i];
	}

	int min_ = 8;
	
	for (int i = 0; i < 8; ++i)
	{

		if(Wr[i] == -1)
			continue;
		else if(Wr[i] < min_)
			min_ = Wr[i];
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

	min_ = 8 - min_;
	max_ =  max_;
	
	char res = (max_ > min_)? 'A' : 'B';
	
	cout<<res<<endl;
	
	return 0;
}
