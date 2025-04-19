#include <bits/stdc++.h>
using namespace std;

int minimum(int threshold, vector<int> points) {
    int n = points.size();
    if (n == 0) return 0;
    if (n == 1) return 1;
    queue<tuple<int, int, int, int>> q; // index, steps, min_val, max_val
    q.push({0, 1, points[0], points[0]}); // Start with first point
    while (!q.empty()) {
        auto [idx, steps, min_val, max_val] = q.front();
        q.pop();
        if (max_val - min_val >= threshold) {
            return steps;
        }
        if (idx + 1 < n) {
            int new_min = min(min_val, points[idx + 1]);
            int new_max = max(max_val, points[idx + 1]);
            q.push({idx + 1, steps + 1, new_min, new_max});
        }
        if (idx + 2 < n) {
            int new_min = min(min_val, points[idx + 2]);
            int new_max = max(max_val, points[idx + 2]);
            q.push({idx + 2, steps + 1, new_min, new_max});
        }
    }
    return n; // fallback: all points visited but condition not met
}

int main() {
    int threshold = 2;
    vector<int> points = {1,2,3};
    int result = minNum(threshold, points);
    cout << result << endl; 

    return 0;
}