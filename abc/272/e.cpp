#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    vector<set<int>> block(M);
    rep(i,N) {
        int d = i + 1;
        if (A[i] < 0) {
            int j = (-A[i] - 1) / d;
            A[i] += j * d;
            for (; j < M; j++) {
                A[i] += d;
                if (A[i] >= N) break;
                block[j].insert(A[i]);
            }
        } else if (A[i] < N) {
            for (int j = 0; j < M; j++) {
                A[i] += d;
                if (A[i] >= N) break;
                block[j].insert(A[i]);
            }
        } else {
            // ignore
        }
    }

    rep(j,M) {
        rep(x,N+1) {
            if (block[j].count(x)) continue;
            cout << x << endl;
            break;
        }
    }
}
