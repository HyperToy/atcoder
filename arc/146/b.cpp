#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    int cnt = 0;
    rep(i,N) if (A[i] > 0) cnt++;
    if (cnt + M < K) {
        cout << 0 << endl;
        return 0;
    }

    // X = 1<<d 以上が達成可能か？ で二分探索
    int ok = 0;
    int ng = 31;
    int rem = 0;
    while (ok + 1 < ng) {
        int d = (ok + ng) / 2;
        int X = (1<<d);
        int msk = 1;
        rep(i,d) (msk *= 2) += 1;
        vector<int> v(N);
        rep(i,N) v[i] = (A[i] & msk);
        sort(v.rbegin(), v.rend());

        ll lack = 0;
        rep(i,K) lack += max(0, (X - v[i]));
        if (lack > M) ng = d;
        else {
            ok = d;
            rem = M - lack;
        }
    }

    int ac = (1<<ok);
    int wa = ac * 2;
    int msk = 1;
    rep(i,ok) (msk *= 2) += 1;
    vector<int> v(N);
    rep(i,N) v[i] = (A[i] & msk);
    sort(v.rbegin(), v.rend());
    while (ac + 1 < wa) {
        int X = (ac + wa) / 2;
        ll lack = 0;
        rep(i,K) lack += max(0, X - v[i]);
        if (lack > M) wa = X;
        else ac = X;
    }

    cout << ac << endl;
} 