#include <iostream>
#include <string>
using namespace std;
string convert(string A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(B <= 1) 
        return A;
        
    string result;  
    int step = 2*B - 2;    
    if(A.size() ==0) 
        return result;  
    for(int i =0; i< B; i++)  
    {  
        for(int j =0, index =i; index < A.size(); j++, index = step*j +i)  
        {  
          result.append(1, A[index]);
          if(i ==0 || i == B-1)
          {            
            continue;  
          }  
          if(index+(B- i-1)*2 < A.size())  
          {  
            result.append(1, A[index+(B- i-1)*2]);  
          }  
        }  
      }  
      return result; 
}
int main(int argc, char const *argv[])
{
  string k ="IshanGupta";
  int n=4;
  string x =convert(k,n);
  cout<<x; 
  return 0;
}