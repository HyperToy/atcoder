#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const long long LINF = 1001001001001001001;
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}

int main(){
    int N, M;
    cin >> N >> M;
    vector x(N, vector<ll>(3));
    rep(i,N) rep(k,3) cin >> x[i][k];
    ll ans = -LINF;

    rep(mask,8) {
        vector<ll> v(N, 0);
        rep(i,N) rep(k,3) v[i] += x[i][k] * ((mask >> k) & 1 ? 1 : -1);
        sort(v.rbegin(), v.rend());
        ll now = 0;
        rep(i,M) now += v[i];
        chmax(ans, now);
    }

    cout << ans << endl;
}
