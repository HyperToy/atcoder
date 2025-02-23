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
    vector<int> bomb(N + 1, 0);
    int r = 0;
    rep(i,N) {
        if (i) bomb[i] += bomb[i - 1];
        while (r < N && m[r].first <= m[i].first + D * 2) r++;
        if (m[i].second > bomb[i]) {
            int num = (m[i].second - bomb[i] + A - 1) / A;
            ans += num;
            bomb[i] += A * num;
            bomb[r] -= A * num;
        }
    }

    cout << ans << endl;
}
