#include <iostream>
#include <vector>
using namespace std;

int countValidSubmatrices(const vector<vector<int>>& A, int N, int M, int K) {
    int count = 0;

    // Iterate over possible submatrix dimensions
    for (int X = 1; X <= N; ++X) {
        for (int Y = 1; Y <= M; ++Y) {
            long long product = 1;  // Use long long to handle large products
            bool isValid = true;

            // Calculate the product of submatrix from A[1][1] to A[X][Y]
            for (int i = 0; i < X && isValid; ++i) {
                for (int j = 0; j < Y && isValid; ++j) {
                    product *= A[i][j];
                    if (product > K) {
                        isValid = false;  // Stop early if the product exceeds K
                    }
                }
            }
            if (isValid && product <= K) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    int N, M, K;
    cout << "Enter dimensions (N M): ";
    cin >> N >> M;
    cout << "Enter K: ";
    cin >> K;

    vector<vector<int>> A(N, vector<int>(M));
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }

    int result = countValidSubmatrices(A, N, M, K);
    cout << "Number of valid submatrices: " << result << endl;

    return 0;
}
