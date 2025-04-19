//remove vowels
#include<iostream>
using namespace std;
bool eq(char s)
{
    
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u'||s=='A'||s=='E'||s=='I'||s=='O'||s=='U')
        {
            return false;
        }
    
    return true;
}
int main()
{
    string s,t="";
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(eq(s[i]))
        {
            t=t+s[i];
        }
    }
    cout<<t<<endl;
}
