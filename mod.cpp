#include <iostream>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

int encryptCode(int S, int N, int M) {
    if (S < 1 || S > MOD || N < 0 || N > MOD || M < 0 || M > MOD)
        return 0;

    // Perform encryption step by step
    int mod10 = S % 10;
    long long powered1 = 1;
    
    for (int i = 0; i < N; i++) {
        powered1 = (powered1 * mod10) % MOD;
    }

    long long powered2 = 1;
    for (int i = 0; i < M; i++) {
        powered2 = (powered2 * powered1) % MOD;
    }

    return powered2;
}

int main() {
    int S, N, M;
    cin >> S >> N >> M;

    int result = encryptCode(S, N, M);
    cout << result << endl;

    return 0;
}
