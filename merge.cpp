#include <bits/stdc++.h>
using namespace std;

// Function to calculate the remaining number of buses
int remainingBuses(vector<pair<int, int>>& routes) {
    // Step 1: Sort the routes by their start points, and by end points if start points are equal
    sort(routes.begin(), routes.end());

    // Step 2: Variables to store merged routes and the current end point
    vector<pair<int, int>> mergedRoutes;
    int currentEnd = -1;

    // Step 3: Traverse through the routes
    for (auto& route : routes) {
        int start = route.first;
        int end = route.second;

        if (start > currentEnd) {
            // Non-overlapping route found
            mergedRoutes.push_back({start, end});
            currentEnd = end;
        } else {
            // Extend the current merged route to include the new route
            currentEnd = max(currentEnd, end);
        }
    }

    // Step 4: Return the count of remaining non-overlapping routes
    return mergedRoutes.size();
}

// Main function
int main() {
    // Example input: Bus routes with their start and end points
    vector<pair<int, int>> routes = {{1, 5}, {3, 7}, {8, 10}, {9, 11}};

    // Calculate and output the number of remaining buses
    cout << "Number of remaining buses: " << remainingBuses(routes) << endl;

    return 0;
}
