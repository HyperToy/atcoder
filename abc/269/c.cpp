#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    ll N;
    cin >> N;

    vector<int> v;
    rep(i,62) {
        if ((N >> i) & 1) {
            v.push_back(i);
        }
    }

    int m = v.size();
    set<ll> ans;
    rep(bit, 1<<m) {
        ll x = 0LL;
        rep(i,m) {
            if ((bit >> i) & 1) {
                x += 1LL << v[i];
            }
        }
        ans.insert(x);
    }

    for (ll x : ans) cout << x << endl;
} 