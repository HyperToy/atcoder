#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

/**
 * BIT の実装の理解をサボった。
 * BIT で転倒数を求める理屈は理解した。
 */

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    ll ans = 0;

    atcoder::fenwick_tree<ll> bit(N);
    rep(i,N) {
        ans += i - bit.sum(0, A[i]);
        bit.add(A[i], 1);
    }

    rep(i,N) {
        cout << ans << endl;
        ans += N - 1 - A[i] * 2;
    }
}
