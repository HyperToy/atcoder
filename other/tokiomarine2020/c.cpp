#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    while (K--) {
        vector<int> B(N, 0);
        rep(i,N) {
            int l = max(0, i - A[i]);
            int r = i + A[i] + 1;
            B[l]++;
            if (r < N) B[r]--;
        }
        rep(i,N-1) B[i + 1] += B[i];

        A = B;
        bool ok = true;
        rep(i,N) if (A[i] != N) ok = false;
        if (ok) break;
    }

    rep(i,N) cout << A[i] << endl;
}
