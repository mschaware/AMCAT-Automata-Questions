#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

double euclideanDistance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double tsp(int n, vector<pair<double, double>>& retailers, int start) {
    int totalStates = 1 << n; // Total subsets of retailers
    vector<vector<double>> dp(totalStates, vector<double>(n, numeric_limits<double>::max()));

    dp[1 << start][start] = 0; // Starting point

    for (int mask = 0; mask < totalStates; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) continue; // Skip if i is not in the subset

            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) continue; // Skip if j is already visited

                int nextMask = mask | (1 << j);
                dp[nextMask][j] = min(dp[nextMask][j], dp[mask][i] + euclideanDistance(retailers[i].first, retailers[i].second, retailers[j].first, retailers[j].second));
            }
        }
    }

    double result = numeric_limits<double>::max();
    for (int i = 0; i < n; ++i) {
        result = min(result, dp[totalStates - 1][i] + euclideanDistance(retailers[i].first, retailers[i].second, retailers[start].first, retailers[start].second));
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of retailers (excluding head retailer): ";
    cin >> n;

    vector<pair<double, double>> retailers(n + 1);
    cout << "Enter the coordinates of the retailers:" << endl;
    for (int i = 0; i <= n; ++i) {
        cin >> retailers[i].first >> retailers[i].second;
    }

    int start;
    cout << "Enter the starting retailer index (0-based): ";
    cin >> start;

    double minDistance = tsp(n + 1, retailers, start);
    cout << "Minimum distance to visit all retailers: " << minDistance << endl;

    return 0;
}
/*#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;

// Function to calculate Euclidean distance between two points
double euclideanDistance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Greedy approach to find the shortest path
double findShortestPath(int n, vector<pair<double, double>>& retailers, int start) {
    vector<bool> visited(n, false);  // Track visited retailers
    visited[start] = true;          // Mark starting retailer as visited

    double totalDistance = 0.0;
    int current = start;

    for (int step = 1; step < n; ++step) {
        double minDistance = numeric_limits<double>::max();
        int nextRetailer = -1;

        // Find the closest unvisited retailer
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                double distance = euclideanDistance(retailers[current].first, retailers[current].second,
                                                    retailers[i].first, retailers[i].second);
                if (distance < minDistance) {
                    minDistance = distance;
                    nextRetailer = i;
                }
            }
        }

        // Visit the next retailer
        visited[nextRetailer] = true;
        totalDistance += minDistance;
        current = nextRetailer;
    }

    return totalDistance;
}

int main() {
    int n;
    cout << "Enter the number of retailers (excluding head retailer): ";
    cin >> n;

    vector<pair<double, double>> retailers(n + 1);
    cout << "Enter the coordinates of the retailers:" << endl;
    for (int i = 0; i <= n; ++i) {
        cin >> retailers[i].first >> retailers[i].second;
    }

    int start;
    cout << "Enter the starting retailer index (0-based): ";
    cin >> start;

    double minDistance = findShortestPath(n + 1, retailers, start);
    cout << "Minimum distance to visit all retailers: " << minDistance << endl;

    return 0;
}
    
*/