#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    ll N, X, M;
    cin >> N >> X >> M;
    vector<ll> A;
    set<ll> s;
    while (s.count(X) == 0) {
        s.insert(X);
        A.push_back(X);
        X = (X * X) % M;
    }

    ll l = A.size();
    vector<ll> sum(l);
    rep(i,l) {
        sum[i] = A[i];
        if (i > 0) {
            sum[i] += sum[i-1];
        }
    }
    
    ll loop_start = -1;
    rep(i,l) {
        if (A[i] == X) {
            loop_start = i;
        }
    }
    ll loop_length = l - loop_start;
    
    ll ans = 0;
    if (loop_start > 0) {
        ans += sum[min(N, loop_start) - 1];
        N -= min(N, loop_start);
        ans += (sum[l-1] - sum[loop_start-1]) * (N / loop_length);
        ans += sum[loop_start + N % loop_length - 1] - sum[loop_start - 1];
    } else {
        ans += sum[l-1] *  (N / loop_length);
        if (N % loop_length > 0) {
            ans += sum[N % loop_length - 1];
        }
    }

    cout << ans << endl;
} 