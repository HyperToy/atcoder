#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    vector<pair<int, int>> A(N), B(N), C(N);
    rep(i,N) A[i].second = B[i].second = C[i].second = -i;
    rep(i,N) cin >> A[i].first, C[i].first += A[i].first;
    rep(i,N) cin >> B[i].first, C[i].first += B[i].first;

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());

    vector<bool> pass(N, false);
    for (int i = 0; i < N && X > 0; i++) {
        if (pass[-A[i].second]) continue;
        pass[-A[i].second] = true;
        X--;
    }
    for (int i = 0; i < N && Y > 0; i++) {
        if (pass[-B[i].second]) continue;
        pass[-B[i].second] = true;
        Y--;
    }
    for (int i = 0; i < N && Z > 0; i++) {
        if (pass[-C[i].second]) continue;
        pass[-C[i].second] = true;
        Z--;
    }

    rep(i,N) if (pass[i]) cout << i + 1 << endl;
}
