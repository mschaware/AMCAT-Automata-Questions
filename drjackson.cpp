#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum vapor rate
int maxVaporRate(vector<int>& set1, vector<int>& set2) {
    // Step 1: Sort set1 in ascending order and set2 in descending order
    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end(), greater<int>());

    // Step 2: Calculate the total vapor rate
    int totalVaporRate = 0;
    for (size_t i = 0; i < set1.size(); i++) {
        totalVaporRate += set1[i] * set2[i];
    }

    // Step 3: Return the result if it's non-negative, otherwise return 0
    return totalVaporRate >= 0 ? totalVaporRate : 0;
}

// Main function
int main() {
    // Example input: Two sets of vapor rates
    vector<int> set1 = {1, 3, 5};
    vector<int> set2 = {6, 4, 2};

    int result = maxVaporRate(set1, set2);
    cout << "Maximum Vapor Rate: " << result << endl;

    return 0;
}
