#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    ll N, X, Y;
    cin >> N >> X >> Y;

    vector<pair<ll, ll>> dp(N);
    dp[0].first = 1;
    dp[0].second = 0;
    rep(i,N-1) {
        dp[i+1].first = dp[i].first * (X + 1) + dp[i].second;
        dp[i+1].second = dp[i].first * X * Y + dp[i].second * Y;
    }

    cout << dp[N-1].second << endl;
} 