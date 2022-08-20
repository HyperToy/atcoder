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

    int cnt = 0;
    rep(i,N) if (A[i] > 0) cnt++;
    if (cnt + M < K) {
        cout << 0 << endl;
        return 0;
    }

    ll ac = 1;
    ll wa = 1LL<<31;
    while (ac + 1 < wa) {
        ll wj = (ac + wa) / 2;
        cerr << wj << endl;
        ll msk = 0;
        while (msk < wj) (msk *= 2) += 1;
        vector<ll> v(N);
        rep(i,N) v[i] = (A[i] & msk);
        sort(v.rbegin(), v.rend());

        ll m = M;
        rep(i,K) {
            for (int d = 31; d >= 0; d--) {
                if (!((wj>>d)&1)) continue;
                if ((v[i]>>d)&1) continue;
                ll msk2 = 1;
                while (msk2 < (1<<d)) (msk2 *= 2) += 1;
                m -= (1<<d) - (v[i]&msk2);
                v[i] = (v[i]&(~msk2)) + (1<<d);
            }
        }
        if (m < 0) wa = wj;
        else ac = wj;
    }

    cout << ac << endl;
} 