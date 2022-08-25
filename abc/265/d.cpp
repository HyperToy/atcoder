#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    vector<ll> P(N);
    cin >> N;
    rep(i,3) cin >> P[i];
    rep(i,2) P[i+1] += P[i];
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> s(N + 1);
    s[0] = 0;
    rep(i,N) s[i+1] = s[i] + A[i];

    rep(x,N+1) {
        bool ok = true;
        rep(i,3) {
            auto itr = lower_bound(s.begin(), s.end(), s[x] + P[i]);
            if (itr == s.end() || s[x] + P[i] != *itr) ok = false;
        }
        if (!ok) continue;
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;

} 