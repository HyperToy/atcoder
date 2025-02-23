#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N, D, K;
    cin >> N >> D >> K;
    vector<int> L(D), R(D);
    rep(i,D) cin >> L[i] >> R[i];
    vector<int> S(K), T(K);
    rep(i,K) cin >> S[i] >> T[i];

    rep(i,K) {
        int pos = S[i];
        rep(j,D) {
            if (L[j] <= pos && pos <= R[j]) {
                if (pos < T[i]) {
                    pos = min(T[i], R[j]);
                } else {
                    pos = max(T[i], L[j]);
                }
                if (pos == T[i]) {
                    cout << j + 1 << endl;
                    break;
                }
            }
        }
    }
}