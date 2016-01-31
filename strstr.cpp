#include <iostream>
#include <string>
using namespace std;
int strStr(const string &haystack, const string &needle) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(haystack[0]==' ')
		return -1;
	if(haystack.length()==0 || needle.length()==0)
		return -1;
	int j=0,i=0,temp;
	for (int i = 0; i < haystack.length(); ++i)
	{
		j=0;
		if(haystack[i]==' ')
			return -1;
		cout<<"haystack "<<haystack[i]<<endl;
        if(haystack[i]==needle[j])
        {
            temp=i+1;
            while(haystack[i]==needle[j])
            {
                i++;
                j++;
                cout<<"needle "<<needle[j]<<endl;
                cout<<"i "<<i<<endl;
                cout<<"j "<<j<<endl;
            	if(haystack.length()==needle.length())
            		break;
            }
            //cout<<"j "<<j<<endl;
			//cout<<"needle "<<needle[j]<<endl;
            if(needle[j]=='\0')
            {
                cout<<"Needle "<<needle[j]<<endl;
                // break;
                if(haystack.length()==needle.length())
                	return temp-1;
                return temp;
            }
            else
            {
                i=temp;
                temp=0;
            }
            cout<<"j "<<j<<endl;
        }
	}
	if(temp==0)
		return -1;
}
int main(int argc, char const *argv[])
{
	string a="bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba";
	string b="babaaa";
	int temp=strStr(a,b);
	if(temp==-1)
		cout<<-1;
	else
		cout<<temp;
	cout<<endl;
	return 0;
}