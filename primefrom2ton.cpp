// #include<bits/stdc++.h>
// using namespace std;

// bool prime(int n)
// {
//     if(n==0||n==1)return 0;
//     for(int i=2;i<=sqrt(n);i++)
//     {
//         if(n%i==0)return 0;
//     }
//     return 1;
// }

// int main()
// {
//     int n,flag=0;
//     cin>>n;
//     for(int i=2;i<=n;i++)
//     {
//         if(prime(i))cout<<i<<endl;
//     }
// }

#include<bits/stdc++.h>
using namespace std;        
bool prime(int n)
{
    if(n==0||n==1)return 0;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)return 0;
    }
    return 1;   
}
int main()
{
    int n,flag=0;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(prime(i))cout<<i<<endl;
    }
}