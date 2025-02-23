#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

void solve() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    int l = -1, r = -1;
    rep(i,N) if (S[i] == '1') {
        if (l == -1) l = i;
        r = i;
    }
    if (l == -1) {
        int cnt = 0;
        int just = 0;
        int now = 0;
        rep(i,N) {
            if (S[i] == '?') {
                now++;
            } else {
                if (now > K) {
                    cout << "No" << endl;
                    return;
                }
                if (now == K) just++;
                now = 0;
            }
        }
        if (now > K) {
            cout << "No" << endl;
            return;
        }
        if (now == K) just++;
        if (just == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
        return;
    }

    for (int i = l; i <= r; i++) if (S[i] == '0') {
        cout << "No" << endl;
        return;
    }

    int L = l, R = r;
    for (int i = l; i >= 0; i--) {
        if (S[i] == '?') L = i;
        if (S[i] == '0') break;
    }
    for (int i = r; i < N; i++) {
        if (S[i] == '?') R = i;
        if (S[i] == '0') break;
    }

    if (r - l + 1 > K) {
        cout << "No" << endl;
        return;
    }
    if (r - l + 1 == K) {
        cout << "Yes" << endl;
        return;
    }
    if ((L == l || R == r ) && R - L + 1 >= K) {
        cout << "Yes" << endl;
        return;
    }
    if (R - L + 1 == K) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
    return;
}

int main(){
    int T;
    cin >> T;
    while (T--) solve();
}
