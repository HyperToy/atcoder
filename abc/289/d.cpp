#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    int M;
    cin >> M;
    vector<int> B(M);
    rep(j,M) cin >> B[j];
    int X;
    cin >> X;
    
    vector<bool> mochi(X + 1, false);
    rep(j,M) mochi[B[j]] = true;

    vector<bool> dp(X + 1, false);
    dp[0] = true;
    rep(j,X) {
        if (mochi[j]) continue;
        if (!dp[j]) continue;
        rep(i,N) if (j + A[i] <= X) dp[j + A[i]] = true;
    }

    if (dp[X]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
