#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    string S, T;
    cin >> N >> S >> T;
    ll ans = 0;
    int i = 0;
    int j = 0;

    while (i < N) {
        if (S[i] == T[i]) {
            i++;
            continue;
        }

        j = max(j, i + 1);
        while (true) {
            if (j == N) {
                cout << -1 << endl;
                return 0;
            }
            if (S[j] == '1') break;
            j++;
        }
        if (j != i + 1) {
            swap(S[j], S[i + 1]);
            ans += j - i - 1;
        }
        if (S[i] == '1') {
            S[i] = S[i + 1] = '0';
        } else {
            S[i] = '1';
            S[i + 1] = '0';
        }
        ans++;
        i++;
    }

    cout << ans << endl;
} 