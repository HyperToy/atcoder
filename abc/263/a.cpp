#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    vector<int> A(5);
    rep(i,5) cin >> A[i];
    sort(A.begin(), A.end());

    bool ok = (A[0] == A[1]) & (A[3] == A[4]) & ((A[2] == A[1]) ^ (A[2] == A[3]));
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
} 