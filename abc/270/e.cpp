#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

int main(){
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> b = A;
    sort(b.begin(), b.end());
    ll pre = 0;
    ll total = 0;
    rep(i,N) {
        ll cnt = N - i;
        ll delta = b[i] - pre;
        pre = b[i];
        if (K >= cnt * delta) {
            K -= cnt * delta;
            total += delta;
        } else {
            delta = K / cnt;
            K -= cnt * delta;
            total += delta;
            break;
        }
    }

    rep(i,N) A[i] = max(0LL, A[i] - total);
    rep(i,N) {
        if (K > 0 && A[i] > 0) {
            A[i]--;
            K--;
        }
    }

    rep(i,N) cout << A[i] << endl;
}