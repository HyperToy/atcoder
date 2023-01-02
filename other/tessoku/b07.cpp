#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int T, N;
    cin >> T >> N;
    vector<int> S(T + 1, 0);
    rep(i,N) {
        int L, R;
        cin >> L >> R;
        S[L] += 1;
        S[R] -= 1;
    }
    rep(i,T) S[i + 1] += S[i];
    rep(i,T) cout << S[i] << endl;
}
