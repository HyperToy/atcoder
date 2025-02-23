#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int n = 4;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    bool ok = false;
    rep(msk,1<<n) {
        int eat = 0;
        rep(i,n) {
            if ((msk >> i) & 1) eat += a[i];
            else eat -= a[i];
        }
        if (eat == 0) {
            ok = true;
        }
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}