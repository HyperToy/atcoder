#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    vector next(20, vector<int>(N + 1, N));
    rep(d,20) {
        for (int i = N - 1; i > 0; i--) {
            if ((A[i] >> d) & 1) next[d][i - 1] = i;
            else next[d][i - 1] = next[d][i];
        }
    }
    ll ans = 0;
    rep(i,N) {
        int mn = N - 1;
        rep(d,20) {
            if ((A[i] >> d) & 1) chmin(mn, next[d][i] - 1);
            else chmin(mn, next[d][next[d][i]] - 1);
        }
        ans += mn - i;
    }
    ans += N;
    cout << ans << endl;
}
