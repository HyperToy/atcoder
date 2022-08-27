#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int bit(int x, int i) {return (x>>i)&1; }
ll msk(int n) {
    ll res = 0;
    rep(i,n) {
        res += (1LL<<i);
    }
    return res;
}

int main(){
    int N, K;
    ll M;
    cin >> N >> M >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    ll ans = 0;
    for (int j = 31; j >= 0; j--) {
        ll x = ans + (1LL<<j);

        vector<ll> v(N);
        rep(i,N) {
            ll b = 0;
            for (int k = 31; k >= 0; k--) {
                if (bit(x,k)) {
                    b += (1LL<<k);
                } else {
                    if (b + msk(k) < A[i]) {
                        b += (1LL<<k);
                    }
                }
            }
            v[i] = b - A[i];
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