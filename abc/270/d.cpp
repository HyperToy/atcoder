#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    rep(i,K) {
        cin >> A[i];
        A[i] = -A[i];
    }
    sort(A.begin(), A.end());

    int a = 0; // Takahashi
    int b = 0; // Aoki
    while (1) {
        auto iter = lower_bound(A.begin(), A.end(), -N);
        if (iter == A.end()) break;
        a -= *iter;
        N += *iter;

        iter = lower_bound(A.begin(), A.end(), -N);
        if (iter == A.end()) break;
        b -= *iter;
        N += *iter;
    }

    cout << a << endl;
}