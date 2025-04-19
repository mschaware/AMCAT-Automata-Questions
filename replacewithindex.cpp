#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr={
        3,0,4,1,2
    };
    vector<int>ans(5,0);
    for(int i=0;i<5;i++)
    {
        ans[arr[i]]=i;
    }
    for(int i=0;i<5;i++)
    {
        cout<<ans[i]<<" ";
    }

}
//Output:
//1 3 4 0 2

/*#include <iostream>
#include <vector>
using namespace std;

void replaceWithIndex(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);

    // Step 1: Fill the temp array using the indices
    for (int i = 0; i < n; ++i) {
        temp[arr[i]] = i;
    }

    // Step 2: Replace the original array with the temp array
    for (int i = 0; i < n; ++i) {
        arr[i] = temp[i];
    }
}

int main() {
    vector<int> arr = {3, 0, 1, 2}; // Example input
    replaceWithIndex(arr);

    cout << "Array after replacing with index values: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/