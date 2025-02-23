#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    vector<ll> sum(N + 1);
    sum[0] = 0;
    rep(i,N) sum[i + 1] = sum[i] + a[i];

    ll ans = 0;
    rep(i, N - K + 1) ans += sum[i + K] - sum[i];

    cout << ans << endl;
}