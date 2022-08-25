#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, M;
    ll T;
    cin >> N >> M >> T;
    vector<ll> A(N);
    rep(i,N-1) cin >> A[i];
    map<int, ll> mp;
    rep(i,M) {
        int X, Y;
        cin >> X >> Y;
        X--;
        mp[X] = Y;
    }

    rep(i,N-1) {
        T += mp[i];
        if (T <= A[i]) {
            cout << "No" << endl;
            return 0;
        }
        T -= A[i];
    }

    cout << "Yes" << endl;
} 