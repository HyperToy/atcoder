#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> odd, even;
    rep(i,N) {
        if (A[i] & 1) odd.push_back(A[i]);
        else even.push_back(A[i]);
    }

    ll ans = -1;
    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    if (odd.size() >= 2) ans = max(ans, odd[0] + odd[1]);
    if (even.size() >= 2) ans = max(ans, even[0] + even[1]);

    cout << ans << endl;
}
