#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
void sortByFrequency(std::vector<int>& arr) 
{
    // Step 1: Count frequencies using unordered_map
    unordered_map<int, int> freqMap;
    for (int num : arr) {
        freqMap[num]++;
    }

    // Step 2: Create a vector of pairs (element, frequency)
    vector<pair<int, int>> freqVec;
    for (const auto& entry : freqMap) {
        freqVec.push_back(entry);
    }

    // Step 3: Sort the vector based on frequency
    sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // Sort in descending order of frequency
    });

    // Step 4: Reconstruct the array based on sorted frequencies
    arr.clear();
    for (const auto& entry : freqVec) {
        for (int i = 0; i < entry.second; ++i) {
            arr.push_back(entry.first);
        }
    }
}

int main() {
    std::vector<int> arr = {4, 5, 6, 5, 4, 3};
    sortByFrequency(arr);

    std::cout << "Sorted by frequency: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
