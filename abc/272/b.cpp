#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> x(M);
    rep(i,M) {
        int k;
        cin >> k;
        x[i].resize(k);
        rep(j,k) {
            cin >> x[i][j];
            x[i][j]--;
        }
    }

    bool ok = true;
    rep(a,N) rep(b,a) {
        bool tmp = false;
        rep(i,M) {
            int p = 0;
            for (int y : x[i]) {
                if (y == a) p++;
                if (y == b) p++;
            }
            if (p == 2) tmp = true;
        }
        if (!tmp) ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
