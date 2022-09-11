#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i,N) cin >> p[i];
    vector<int> ip(N);
    rep(i,N) ip[p[i]] = i;

    ll ans = 0;
    rep(i,N) {
        int d = (p[i] - i + N) % N;
        ans += min(d, N - d);
    }

    ll delta = 0;
    vector<int> e(N, 0);
    rep(i,N) {
        // d 回操作すると 人i の不満度が0になる
        int d = (ip[i] - i + N) % N;
        if (d <= N / 2) delta--;
        if (d > (N+1) / 2) delta++;
        e[d]+=2;
        e[(d+N/2)%N]--;
        e[(d+(N+1)/2)%N]--;
    }

    ll now = ans;
    rep(i,N) {
        now += delta;
        ans = min(ans, now);
        delta += e[i];
    }
    cout << ans << endl;
} 