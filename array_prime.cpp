#include <iostream>
#include <vector>
using namespace std;

int main()
{
   int N,t;
   cin>>N;
   vector<int> v;
   for (int i = 0; i < N; ++i)
   {
   		cin>>t;
   		v.push_back(t);
   }
   sort(v.begin(),v.end());
   return 0;
}
