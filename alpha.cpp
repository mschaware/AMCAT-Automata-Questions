// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int titleToNumber(string c) {
        map<char, int> alphabetMap;
        int value = 1; 
        for (char ch = 'A'; ch <= 'Z'; ++ch) {
            alphabetMap[ch] = value++;
        }
        int ans=0;
        // for(int i=0;i<c.size();i++)
        // {
        //     ans=ans+alphabetMap[c[i]]*(pow(26,i));
        //     cout<<ans<<" ";
        // }
        // ans=ans+alphabetMap[c[0]]*(pow(26,0));
        //     cout<<ans<<" ";
            
            ans=ans+alphabetMap[c[1]]*(pow(26,1));
            cout<<ans<<" ";
        
        
        return ans;
    }
int main() {
    
    //int a=titleToNumber("AB");
    //cout<<a<<endl;
    string s="asdxds";
    cout<<s[0];
    return 0;
}
