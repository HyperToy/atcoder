#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    ll P, Q, R;
    cin >> N >> P >> Q >> R;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> s(N + 1);
    s[0] = 0;
    rep(i,N) s[i+1] = s[i] + A[i];

    rep(x,N+1) {
        auto itrx = lower_bound(s.begin(), s.end(), s[x] + P);
        if (itrx == s.end() || s[x] + P != *itrx) {
            continue;
        }
        int y = itrx - s.begin();
        auto itry = lower_bound(s.begin(), s.end(), s[y] + Q);
        if (itry == s.end() || s[y] + Q != *itry) {
            continue;
        }
        int z = itry - s.begin();
        auto itrz = lower_bound(s.begin(), s.end(), s[z] + R);
        if (itrz == s.end() || s[z] + R != *itrz) {
            continue;
        }
        int w = itrz - s.begin();
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;

} 