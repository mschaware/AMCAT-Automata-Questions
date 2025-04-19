#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m1[3][3],m2[3][3];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>m1[i][j];
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>m2[i][j];
        }
    }

    int eq=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(m1[i][j]!=m2[i][j])
            {
                eq=0;
            }
        }
    }

    if(eq==1)cout<<"Equal"<<endl;
    else cout<<"Not equal"<<endl;
}