#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

pair<ll, ll> dfs(int n, pair<ll, ll> p, ll X, ll Y) {
    if (n == 1) return p;
    pair<ll, ll> res;
    res.first = (X + 1) * p.first + p.second;
    res.second = X * Y * p.first + Y * p.second;
    return dfs(n-1, res, X, Y);
}

int main(){
    ll N, X, Y;
    cin >> N >> X >> Y;

    pair<ll, ll> ans = dfs(N, pair(1, 0), X, Y);
    cout << ans.second << endl;
}