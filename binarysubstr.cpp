#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    string start = "1010";
    string end = "0011";
    int n = start.length();

    // Create a dynamic programming table to track transformations
    vector<map<string, string>> dp(31); // dp[i] stores all reachable strings at step i
    dp[1][start] = ""; // Initially, only the start string is reachable

    // Perform dynamic programming to compute transformations
    for (int i = 2; i <= n; ++i) {
        for (const auto &entry : dp[i - 1]) {
            string currentString = entry.first;
            for (int j = 0; j <= n - i; ++j) {
                // Reverse substring of length i starting at position j
                string newString = currentString;
                reverse(newString.begin() + j, newString.begin() + j + i);
                dp[i][newString] = currentString; // Store predecessor
            }
        }

        // Check if the target string is reachable at this step
        if (dp[i].count(end)) {
            cout << i - 1 << endl; // Return the count of steps (minimum steps)
            return 0;
        }
    }

    cout << "-1" << endl; // Return -1 if transformation is not possible
    return 0;
}
