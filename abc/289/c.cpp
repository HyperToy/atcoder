#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(M);
    rep(i,M) {
        int C;
        cin >> C;
        a[i].resize(C);
        rep(j,C) cin >> a[i][j];
    }

    int ans = 0;
    rep(msk, 1 << M) { // O(2^M)
        set<int> st;
        rep(i,M) if ((msk >> i) & 1) { // O(M)
            for (int x : a[i]) st.insert(x); // O(N)
        }
        if (st.size() == N) ans++;
    }

    cout << ans << endl;
}
