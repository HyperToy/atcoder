#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, K, M, R;
    cin >> N >> K >> M >> R;
    vector<int> S(N, 0);
    rep(i,N-1) cin >> S[i];

    ll req_sum = (ll)K * R;
    sort(S.rbegin(), S.rend());

    ll now_sum = 0;
    rep(i,K) now_sum += S[i];
    if (now_sum >= req_sum) {
        cout << 0 << endl;
        return 0;
    }

    now_sum -= S[K-1];
    if (req_sum > now_sum + M) {
        cout << -1 << endl;
        return 0;
    }

    cout << req_sum - now_sum << endl;
    return 0;
}