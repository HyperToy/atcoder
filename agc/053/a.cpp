#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 1001001001;

int main(){
    int N;
    string S;
    cin >> N >> S;
    vector<int> A(N+1);
    rep(i,N+1) cin >> A[i];

    int k = INF;
    rep(i,N) k = min(k, abs(A[i] - A[i+1]));
    cout << k << endl;
    
    rep(i,k) rep(j,N+1) {
        int b = A[j] / k;
        if (i < A[j] % k) b++;
        cout << b;
        if (j < N) cout << " ";
        else cout << endl;
    }
} 