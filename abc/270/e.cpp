#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    priority_queue<ll, vector<ll>, greater<ll>> q;
    rep(i,N) {
        q.push(A[i]);
    }

    ll diff = 0;
    ll total = 0;
    bool go = true;
    while (go) {
        diff = q.top() - total;
        q.pop();
        if (K < diff * (q.size() + 1)) {
            diff = K / (q.size() + 1);
            go = false;
        }
        K -= diff * (q.size() + 1);
        total += diff;
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