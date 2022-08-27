#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, K;
    ll M;
    cin >> N >> M >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    ll ans = 0;
    for (int i = 35; i >= 0; i--) {
        ll x = ans + (1LL << i);
        vector<ll> v;
        for (ll a : A) {
            ll b = 0;
            for (int j = 35; j >= 0; j--) {
                if (x >> j & 1) {
                    b += 1LL << j;
                } else {
                    if (b + (1LL << j) - 1 < a) {
                        b += 1LL << j;
                    }
                }
            }
            v.push_back(b - a);
        }
        sort(v.begin(), v.end());
        ll cost = 0;
        rep(i,K) {
            cost += v[i];
        }
        if (cost <= M) {
            ans = x;
        }
    }

    cout << ans << endl;
} 