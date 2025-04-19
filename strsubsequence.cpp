#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; // Eliminates the need for std:: prefixes

string longestIncreasingSubsequence(const string& str) {
    vector<char> lis; // Vector to store the longest increasing subsequence

    for (char c : str) {
        auto it = lower_bound(lis.begin(), lis.end(), c);
        if (it == lis.end()) {
            lis.push_back(c); // Add character to LIS
        } else {
            *it = c; // Replace existing element in LIS
        }
    }

    return string(lis.begin(), lis.end());
}

int main() {
    string str = "abacbdce";
    string result = longestIncreasingSubsequence(str);

    cout << "Longest increasing subsequence: " << result << endl;
    return 0;
}
