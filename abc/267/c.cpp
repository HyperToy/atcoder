#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
const long long LINF = 1001001001001001001;

int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> sum(N+1, 0), mulsum(N+1, 0);
    rep(i,N) {
        sum[i+1] = sum[i] + A[i];
        mulsum[i+1] = mulsum[i] + A[i] * (i+1);
    }

    ll ans = -LINF;
    rep(i,N-M+1) {
        ll now = mulsum[i+M] - mulsum[i] - (sum[i+M] - sum[i]) * i;
        chmax(ans, now);
    }

    cout << ans << endl;
} 