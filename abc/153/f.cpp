#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, D, A;
    cin >> N >> D >> A;
    vector<pair<int, int>> m(N);
    rep(i,N) cin >> m[i].first >> m[i].second;

    sort(m.begin(), m.end());

    ll ans = 0;
    ll power = 0;
    vector<ll> down(N + 1, 0);
    int r = 0;
    rep(i,N) {
        power -= down[i];
        m[i].second -= power;
        while (r < N && m[r].first <= m[i].first + D * 2) r++;
        int num = (max(0, m[i].second) + A - 1) / A;
        power += A * num;
        down[r] += A * num;
        ans += num;
    }

    cout << ans << endl;
}
