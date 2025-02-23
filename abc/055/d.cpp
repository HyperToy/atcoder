#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    string s;
    cin >> N >> s;

    rep(msk,4) {
        vector<bool> sheep(N, false);
        rep(i,2) sheep[i] = msk >> i & 1;

        for (int i = 1; i < N - 1; i++) {
            sheep[i + 1] = (sheep[i] ^ (s[i] == 'o') ^ sheep[i - 1]);
        }
        
        bool ok = true;
        ok = ok && (sheep[0] ^ s[0] == 'o' ^ (sheep[1] == sheep[N-1]));
        ok = ok && (sheep[N-1] ^ s[N-1] == 'o' ^ (sheep[0] == sheep[N-2]));

        if (ok) {
            string ans = string(N, '.');
            rep(i,N) ans[i] = sheep[i] ? 'S' : 'W';
            cout << ans << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}