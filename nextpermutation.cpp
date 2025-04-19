#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    // Example with a vector of integers
    vector<int> nums = {1, 2, 3};
    
    if (next_permutation(nums.begin(), nums.end())) {
        cout << "Next permutation: ";
        for (int num : nums) {
            cout << num << " ";
        }
    } else {
        cout << "No next permutation, it's the last one!" << endl;
    }

    // Example with a string
    string str = "abc";
    if (next_permutation(str.begin(), str.end())) {
        cout << "\nNext permutation of string: " << str << endl;
    } else {
        cout << "\nNo next permutation, it's the last one!" << endl;
    }

    return 0;
}
