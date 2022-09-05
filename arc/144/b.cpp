#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
const int INF = 1001001001;

int main(){
    int N;
    ll a, b;
    cin >> N >> a >> b;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    sort(A.rbegin(), A.rend());

    ll ac = 1;
    ll wa = INF;
    while (ac + 1 < wa) {
        ll wj = (ac + wa) / 2;
        ll cnt = 0;
        rep(i,N) {
            if (A[i] > wj) cnt += (A[i] - wj) / b;
            else cnt -= (wj - A[i] + a - 1) / a;
        }
        if (cnt >= 0) ac = wj;
        else wa = wj;
    }

    cout << ac << endl;
} 