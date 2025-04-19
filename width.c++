#include <iostream>
using namespace std;

int maxHeight(int n) {
    int height = 0;
    int boxesNeeded = 0;
    for (int i = 1; boxesNeeded + i <= n; i++) 
    {
        boxesNeeded += i;
        height++;
    }
    return height;
}

int main() {
    //int n;

    // // Test case 1
    // n = 5;
    // cout << "Input: " << n << ", Output: " << maxHeight(n) << endl;

    // // Test case 2
    // n = 6;
    // cout << "Input: " << n << ", Output: " << maxHeight(n) << endl;

    // // Test case 3
    // n = 10;
    // cout << "Input: " << n << ", Output: " << maxHeight(n) << endl;


    int n;
    cout<<"Enter n "<<endl;
    cin>>n;
    cout << "Input: " << n << ", Output: " << maxHeight(n) << endl;


    return 0;
}
