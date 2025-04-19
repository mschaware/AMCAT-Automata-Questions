#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the longest consecutive subsegment of 1s
int longestConsecutiveOnes(const string &S, int K) {
    int n = S.size();
    int maxLength = 0;
    int left = 0, zeros = 0;

    for (int right = 0; right < n; right++) {
        if (S[right] == '0') zeros++;

        // Shrink the window until zeros <= K
        while (zeros > K) {
            if (S[left] == '0') zeros--;
            left++;
        }

        // Calculate the max length
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    // Edge Cases
    vector<pair<string, int>> testCases = {
        {"", 1},         // Empty string
        {"11111", 2},    // No zeros
        {"00000", 3},    // No ones
        {"1101001", 5},  // K larger than zeros
        {"0", 1},        // Single character string
        {"1010101", 2},  // Alternating pattern
        {"11100000", 3}, // Continuous zeros at one end
        {"10101", 0},    // K equals zero
        {"00000", 5},    // All zeros with K equal to length
        {"0101010", 3}   // Multiple similar results
    };

    // Run tests
    for (const auto &testCase : testCases) {
        const string &S = testCase.first;
        int K = testCase.second;
        cout << "Input: S = \"" << S << "\", K = " << K << endl;
        cout << "Longest consecutive 1s: " << longestConsecutiveOnes(S, K) << endl;
        cout << "----------------------" << endl;
    }

    return 0;
}
