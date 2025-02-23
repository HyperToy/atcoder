#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1);
    dp[1] = dp[2] = 0;
    dp[3] = 1;
    int mod = 10007;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        dp[i] %= mod;
    }
    cout << dp[n] << endl;
}