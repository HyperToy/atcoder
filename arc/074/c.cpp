#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PR(x) cerr << #x << " = " << x << endl
const long long LINF = 1001001001001001001;
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

// 横3つに分割
ll a(ll h, ll w) {
    ll mn = w / 3 * h;
    ll mx = (w + 2) / 3 * h;
    return mx - mn;
}

// T字型に分割
ll b(ll h, ll w) {
    ll res = LINF;

    vector<ll> v;
    v.push_back(h / 3 * w);
    v.push_back((h - h / 3) * (w / 2));
    v.push_back((h - h / 3) * ((w + 1) / 2));
    sort(v.begin(), v.end());
    chmin(res, v[2] - v[0]);

    v.clear();
    v.push_back((h + 2) / 3 * w);
    v.push_back((h - (h + 2) / 3) * (w / 2));
    v.push_back((h - (h + 2) / 3) * ((w + 1) / 2));
    sort(v.begin(), v.end());
    chmin(res, v[2] - v[0]);

    return res;
}

int main(){
    ll H, W;
    cin >> H >> W;

    ll ans = LINF;
    chmin(ans, a(H, W));
    chmin(ans, a(W, H));
    chmin(ans, b(H, W));
    chmin(ans, b(W, H));

    cout << ans << endl;

} 