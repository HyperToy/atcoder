#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    ll C;
    cin >> N >> C;
    vector<int> a(N), b(N), c(N);
    rep(i,N) cin >> a[i] >> b[i] >> c[i];

    map<ll, ll> mp;
    mp[0] = 0;
    rep(i,N) {
        mp[a[i]] += c[i];
        mp[b[i]+1] -= c[i];
    }

    ll ans = 0;
    ll cost = 0;
    ll pre = 0;
    for (auto p : mp) {
        ans += min(C, cost) * (p.first - pre);
        cost += p.second;
        pre = p.first;
    }

    cout << ans << endl;
} 