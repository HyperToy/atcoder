#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> a(N);
    rep(i,N) {
        int L;
        cin >> L;
        a[i].resize(L);
        rep(j,L) cin >> a[i][j];
    }
    rep(_,Q) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        cout << a[s][t] << endl;
    }
}