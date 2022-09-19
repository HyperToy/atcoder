#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int popcount(string X) {
    int res = 0;
    for (char k : X) if (k == '1') res++;
    return res;
}

int main(){
    int N;
    string X;
    cin >> N >> X;
    int K = popcount(X);

    // dp[i] := i → 0 に必要な操作回数
    vector<int> dp(N, 0);
    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        int k = __builtin_popcount(i);
        dp[i] = dp[i % k] + 1;
    }

    // e[j][i] := 2 ^ i (mod popcount(X) - 1 + j)
    vector<vector<int>> e(3, vector<int>(N));

    // sum[j] := e[j] のうち X の (下から)jビット目 が立っているものの 総和
    vector<int> sum(3, 0);

    rep(j,3) {
        int k = K - 1 + j;
        if (k == 0) continue;
        rep(i,N) {
            if (i == 0) e[j][i] = 1 % k;
            else e[j][i] = (e[j][i-1] * 2) % k;
            if (X[N - i - 1] == '1') {
                (sum[j] += e[j][i]) %= k;
            }
        }
    }

    rep(i,N) {
        if (X[i] == '1') {
            // j = 0;
            int k = K - 1;
            if (k == 0) {
                cout << 0 << endl;
                continue;
            }
            int x = (sum[0] - e[0][N - i - 1] + k) % k;
            cout << dp[x] + 1 << endl;
        } else {
            // j = 2;
            int k = K + 1;
            int x = (sum[2] + e[2][N - i - 1]) % k;
            cout << dp[x] + 1 << endl;
        }
    }

    return 0;
}