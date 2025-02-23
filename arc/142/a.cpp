#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    string N, K;
    cin >> N >> K;
    int n = N.length();
    int k = K.length();

    if (n < k) {
        cout << 0 << endl;
        return 0;
    }

    for (int i=0, j=k-1; i<j; i++, j--) {
        if (K[i] < K[j]) break;
        if (K[i] == K[j]) continue;
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    rep(_,2) {
        string X = K;
        int x = X.length();
        if (x < n) {
            ans += n - x;
        }
        if (X + string(n-x, '0') <= N) {
            ans += 1;
        }
        reverse(K.begin(), K.end());
        if (X == K) break;
    }

    cout << ans << endl;
}