#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    int cnt = 0;
    rep(i,N) {
        cin >> a[i];
        a[i]--;
        if (a[i] == i) {
            cnt++;
        }
    }
    ll ans = (ll)cnt * (cnt - 1) / 2;
    rep(i,N) {
        if (a[i] > i && a[a[i]] == i) {
            ans++;
        }
    }
    cout << ans << endl;
}
