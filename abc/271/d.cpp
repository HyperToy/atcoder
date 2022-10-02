#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N, S;
    cin >> N >> S;
    vector<int> a(N), b(N);
    rep(i,N) cin >> a[i] >> b[i];

    vector<vector<bool>> dp(N+1, vector<bool>(S+1, false));
    dp[0][0] = true;
    rep(i,N) {
        rep(j,S+1) {
            if (dp[i][j]) {
                if (j + a[i] <= S) dp[i+1][j + a[i]] = true;
                if (j + b[i] <= S) dp[i+1][j + b[i]] = true;
            }
        }
    }

    if (dp[N][S]) {
        cout << "Yes" << endl;
        string ans = "";
        int now = S;
        for (int i = N; i > 0; i--) {
            if (now - a[i-1] >= 0 && dp[i-1][now - a[i-1]]) {
                ans += 'H';
                now -= a[i-1];
            } else {
                ans += 'T';
                now -= b[i-1];
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    } else {
        cout << "No" << endl;
    }
}