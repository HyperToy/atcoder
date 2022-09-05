#include <bits/stdc++.h>
using namespace std;
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 1; i < N; i++) cin >> P[i], P[i]--;

    vector<int> dp(N);
    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        dp[i] = dp[P[i]] + 1;
    }

    cout << dp[N-1] << endl;
} 