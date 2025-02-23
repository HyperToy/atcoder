#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> ng(3);
    rep(i,3) cin >> ng[i];

    rep(i,3) if (N == ng[i]) {
        cout << "NO" << endl;
        return 0;
    }

    rep(_,100) {
        if (N == 0) break;
        int next = -1;
        for (int i = 3; i >=1; i--) {
            if (N - i < 0) continue;
            bool ok = true;
            rep(j,3) if (N - i == ng[j]) ok = false;
            if (ok) {
                next = N - i;
                break;
            }
        }
        if (next == -1) {
            cout << "NO" << endl;
            return 0;
        }
        N = next;
    }
    if (N > 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}