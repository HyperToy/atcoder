#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int T, N, M;
    cin >> T >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    cin >> M;
    vector<int> B(M);
    rep(i,M) cin >> B[i];

    if (N < M) {
        cout << "no" << endl;
        return 0;
    }
    
    int i = 0;
    rep(j,M) {
        if (A[i] > B[j]) {
            cout << "no" << endl;
            return 0;
        }
        while (i < N && A[i] + T < B[j]) i++;
        if (i == N) {
            cout << "no" << endl;
            return 0;
        }
        i++;
    }
    cout << "yes" << endl;
    return 0;
}