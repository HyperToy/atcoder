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
    vector<pair<ll, ll>> v;
    ll pre = 0;
    rep(i,N) {
        v.emplace_back(N - i, b[i] - pre);
        pre = b[i];
    }

    ll total = 0;
    rep(i,N) {
        if (K >= v[i].first * v[i].second) {
            K -= v[i].first * v[i].second;
            total += v[i].second;
        } else {
            ll delta = K / v[i].first;
            K -= v[i].first * delta;
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