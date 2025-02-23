#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    int gcd = a[0];
    rep(i,N) gcd = __gcd(gcd, a[i]);
    rep(i,N) a[i] /= gcd;

    int ans = 0;
    rep(i,N) {
        for (int d = 2; d <= 3; d++) {
            while (a[i] % d == 0) {
                a[i] /= d;
                ans++;
            }
        }
        if (a[i] != 1) {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
}
