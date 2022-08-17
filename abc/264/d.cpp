#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string S;
    cin >> S;

    string T = "atcoder";
    int l = T.length();
    int ans = 0;
    rep(i,l) {
        int pos = -1;
        rep(j,l) {
            if (S[j] == T[i]) {
                pos = j;
                break;
            }
        }
        ans += pos - i;
        for (int j = pos; j > i; j--) {
            swap(S[j-1], S[j]);
        }
    }

    cout << ans << endl;
}
