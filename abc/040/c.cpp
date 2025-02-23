#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 1001001001;
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    vector<int> dp(N, INF);
    dp[0] = 0;
    dp[1] = abs(a[0] - a[1]);
    for (int i = 2; i < N; i++) {
        chmin(dp[i], abs(a[i] - a[i-1]) + dp[i-1]);
        chmin(dp[i], abs(a[i] - a[i-2]) + dp[i-2]);
    }

    cout << dp[N-1] << endl;
}