#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int power(int k, int n) {
    int res = 1;
    rep(_,n) res *= k;
    return res;
}

int bit(int msk, int k, int n) {
    rep(_,n) msk /= k;
    return msk % k;
}

int main(){
    int N, K;
    cin >> N >> K;
    vector T(N, vector<int>(K));
    rep(i,N) rep(j,K) cin >> T[i][j];

    rep(msk, power(K, N)) {
        int now = 0;
        rep(i,N) {
            now ^= T[i][bit(msk, K, i)];
        }
        if (now == 0) {
            cout << "Found" << endl;
            return 0;
        }
    }

    cout << "Nothing" << endl;
    return 0;
}