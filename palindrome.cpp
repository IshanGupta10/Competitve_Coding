#include <iostream>
#include <vector>
#include <string>
using namespace std;
int isPalindrome(string A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int size = A.length();
    string lcs;
    for (int i=0; A[i]; i++) 
    lcs.push_back(tolower(A[i]));
    int left = 0;
    int right = size - 1;
    while(right >= left) 
    {
        if(lcs.at(right) == lcs.at(left)) 
        {
            right--;
            left++;
        }
        else if(!isalpha(lcs.at(right))) 
            right--;
        else if(!isalpha(lcs.at(left))) 
            left++;
        else 
            return false;
    }
    if(left==right)
        return false;
    return true;
}
int main(int argc, char const *argv[])
{
    string s="1a2";
    int k;
    k=isPalindrome(s);
    cout<<k;
    return 0;
}