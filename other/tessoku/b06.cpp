#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    vector<int> S(N + 1, 0);
    rep(i,N) S[i + 1] = S[i] + A[i];

    int Q;
    cin >> Q;
    rep(_,Q) {
        int L, R;
        cin >> L >> R;
        int ok = S[R] - S[L - 1];
        int ng = R - L + 1 - ok;
        if (ok > ng) cout << "win" << endl;
        else if (ok == ng) cout << "draw" << endl;
        else cout << "lose" << endl;
    }
}
