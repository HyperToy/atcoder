#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    pair<int, int> A[4];
    rep(i,4) cin >> A[i].first >> A[i].second;

    bool ok = true;
    rep(i,2) {
        rep(j,2) {
            int x, y, z, w;
            x = A[(i+j+1) % 4].first - A[i].first;
            y = A[(i+j+1) % 4].second - A[i].second;
            z = A[(i+j+2) % 4].first - A[i].first;
            w = A[(i+j+2) % 4].second - A[i].second;
            if (x * w - y * z < 0) ok = false;
        }
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
} 