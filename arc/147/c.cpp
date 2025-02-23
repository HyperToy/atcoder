#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    cin >> N;
    vector<pair<ll, int>> L(N), R(N);
    rep(i,N) {
        cin >> L[i].first >> R[i].first;
        L[i].second = R[i].second = i;
    }

    ll ans = 0;
    sort(L.rbegin(), L.rend());
    sort(R.begin(), R.end());
    set<int> used;
    int li = 0;
    int ri = 0;
    int rem = N;

    while (1) {
        if (rem < 2) break;
        while (used.count(L[li].second) > 0) li++;
        while (used.count(R[ri].second) > 0) ri++;
        used.insert(L[li].second);
        used.insert(R[ri].second);

        if (L[li].first <= R[ri].first) break;
        rem -= 2;
        ans += (rem + 1) * (L[li].first - R[ri].first);
    }

    cout << ans << endl;
} 