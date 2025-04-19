#include <iostream>
#include <vector>
using namespace std;

void dfs(int city, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[city] = true;
    for (int neighbor : adj[city]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int countClusters(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    int clusters = 0;

    for (int city = 0; city < n; ++city) {
        if (!visited[city]) {
            dfs(city, adj, visited);
            clusters++; // Each DFS corresponds to one cluster
        }
    }

    return clusters;
}

int main() {
    int n = 6; // Number of cities
    vector<vector<int>> adj = {
        {1, 2}, // Roads for city 0
        {0, 3}, // Roads for city 1
        {0},    // Roads for city 2
        {1},    // Roads for city 3
        {5},    // Roads for city 4
        {4}     // Roads for city 5
    };

    cout << "Total number of clusters: " << countClusters(adj, n) << endl;
    return 0;
}
