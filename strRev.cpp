#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}
void reverseWords(string &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    char *word_begin = NULL;
    char *temp = &A[0];
    for (string::iterator i = A.begin(); i != A.end(); ++i)
    {
        if(*i != ' ')
            break;
        A.erase(i);
        i--;
    }
    while( *temp )
    {
        if (( word_begin == NULL ) && (*temp != ' ') )
        {
            word_begin=temp;
        }
        if(word_begin && ((*(temp+1) == ' ') || (*(temp+1) == '\0')))
        {
            reverse(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    }
    reverse(&A[0], temp-1);
    for (string::iterator i = A.begin(); i != A.end(); ++i)
    {
        if(*i == ' ' && *(i+1) == ' ')
            {
                A.erase(i+1);
                i--;
            }
    }
    for (string::iterator i = A.begin(); i != A.end(); ++i)
    {
        if(*i != ' ')
            break;
        A.erase(i);
        i--;
    }
}
int main(int argc, char const *argv[])
{
    string s="tzivdbfsp d miwzpqolwg rjayff sehlnrrgo  iupri lwptm vfos e ueimmt rckfhpjvbk  ";
    reverseWords(s);
    cout<<s<<endl;
    return 0;
}