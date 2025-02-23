#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N, Q;
    cin >> N >> Q;
    
    vector<int> imos(N, 0);
    rep(_,Q) {
        int l, r;
        cin >> l >> r;
        l--;
        imos[l]++;
        if (r < N) imos[r]--;
    }
    rep(i,N-1) imos[i+1] += imos[i];

    string ans = string(N, '0');
    rep(i,N) {
        if (imos[i] & 1) ans[i] = '1';
    }

    cout << ans << endl;
}