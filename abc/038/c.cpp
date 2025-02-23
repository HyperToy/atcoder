#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    ll l = 0, r = 0;
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        if (a[i - 1] < a[i]) {
            r = i + 1;
        } else {
            ans += (r - l) * (r - l - 1) / 2;
            l = i;
            r = i;
        }
    }
    ans += (r - l) * (r - l - 1) / 2;
    ans += N;
    cout << ans << endl;
}