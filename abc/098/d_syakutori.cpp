#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    int l = 0;
    int r = 0;
    int x = 0;
    ll ans = 0;
    while (l < N) {
        while (r < N && !(x & A[r])) {
            x ^= A[r];
            r++;
        }
        ans += r - l;
        x ^= A[l];
        l++;
    }

    cout << ans << endl;
}
