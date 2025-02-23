#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> a(N), b(M);
    rep(i,N) cin >> a[i];
    rep(j,M) cin >> b[j];

    int now = 0;
    int ans = 0;
    while (1) {
        auto iter = lower_bound(a.begin(), a.end(), now);
        if (iter == a.end()) break;
        now = *iter + X;

        iter = lower_bound(b.begin(), b.end(), now);
        if (iter == b.end()) break;
        now = *iter + Y;
        ans++;
    }

    cout << ans << endl;
}