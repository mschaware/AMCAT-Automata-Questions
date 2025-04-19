#include<bits/stdc++.h>
using namespace std;
int nc(vector<int>&arr1,vector<int>&arr2)
{
    vector<int>ans;
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    int i=0,j=0;
    while(i<=5&&j<=5)
    {
        if(arr1[i]==arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;j++;
        }
        else if(arr1[i]!=arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else 
        {
            ans.push_back(arr2[i]);
            j++;
        }
    }

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

    return ans.size();
}
int main()
{
    vector<int>arr1(5),arr2(5);
    for(int i=0;i<5;i++)
    cin>>arr1[i];
    for(int i=0;i<5;i++)
    cin>>arr2[i];

    int a=nc(arr1,arr2);
    cout<<endl<<a;
}