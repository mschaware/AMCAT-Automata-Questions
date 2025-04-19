#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Helper function: Perform BFS to calculate the area of a house
int bfs(vector<vector<int>>& grid, int i, int j) {
    int rows = grid.size();
    int cols = grid[0].size();
    int area = 0;

    // Directions for adjacent cells (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;

    // Start BFS from the current cell
    q.push({i, j});
    grid[i][j] = 0; // Mark the cell as visited by setting it to 0

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        area++;

        for (auto direction : directions) {
            int dx = direction.first;
            int dy = direction.second;
            int newX = x + dx;
            int newY = y + dy;

            // Check bounds and if the cell is part of a house
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                q.push({newX, newY});
                grid[newX][newY] = 0; // Mark as visited
            }
        }
    }
    return area;
}

// Main function to find the largest house area
int largestHouseArea(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    int maxArea = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                // Call BFS and update maxArea
                maxArea = max(maxArea, bfs(grid, i, j));
            }
        }
    }
    return maxArea;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = largestHouseArea(grid);
    cout << result << endl;

    return 0;
}
