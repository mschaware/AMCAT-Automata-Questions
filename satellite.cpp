#include <bits/stdc++.h>
using namespace std;

// Function to count the number of 1s in the binary representation of a number
int countOnes(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1; // Check the last bit
        num >>= 1;        // Shift right to remove the last bit
    }
    return count;
}

// Function to perform the handshake mechanism
vector<int> satelliteHandshake(vector<int>& stream, int M) {
    // Sort the stream based on the count of 1s, then by magnitude
    sort(stream.begin(), stream.end(), [](int a, int b) {
        int countA = countOnes(a);
        int countB = countOnes(b);
        if (countA == countB) return a > b; // Larger number first
        return countA > countB;             // More 1s first
    });

    // Return the top M numbers
    vector<int> result(stream.begin(), stream.begin() + M);
    return result;
}

int main() {
    // Input: Stream of numbers and value of M
    int N, M;
    cin >> N >> M;
    vector<int> stream(N);
    for (int i = 0; i < N; i++) {
        cin >> stream[i];
    }

    // Perform the handshake
    vector<int> result = satelliteHandshake(stream, M);

    // Output the result
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
