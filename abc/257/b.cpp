#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<bool> field(N, false);
    vector<int> A(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
        A[i]--;
        field[A[i]] = true;
    }
    for (int _ = 0; _ < Q; _++) {
        int L;
        cin >> L;
        --L;
        if (A[L] == N-1) continue;
        if (field[A[L]+1]) continue;
        field[A[L]] = false;
        A[L]++;
        field[A[L]] = true;
    }
    for (int i = 0; i < K; i++) {
        cout << A[i] + 1 << endl;
    }
}
