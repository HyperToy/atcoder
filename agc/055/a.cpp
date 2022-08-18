#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    string S;
    cin >> N >> S;

    string s = "ABC";
    string ans(N * 3, '.');
    int num = 0;
    do {
        num++;
        vector<int> a(3, 0);
        while (true) {
            bool ok = true;
            rep(i,3) {
                for (; a[i] < N; a[i]++) {
                    if (S[a[i] + N * i] == s[i] && ans[a[i] + N * i] == '.') {
                        break;
                    }
                }
                if (a[i] >= N) ok = false;
            }
            if (!ok) break;

            rep(i,3) {
                ans[a[i] + N * i] = num + '0';
                a[i]++;
            }
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << ans << endl;
} 