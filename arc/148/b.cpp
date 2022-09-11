#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

char conv(char c) {
    if (c == 'd') return 'p';
    else return 'd';
}

string f(string s, int l, int r) {
    for (;l <= r; l++, r--) {
        swap(s[l], s[r]);
        s[l] = conv(s[l]);
        if (l != r) s[r] = conv(s[r]);
    }
    return s;
}

int main(){
    int N;
    string S;
    cin >> N >> S;

    int L = N;
    rep(i,N) {
        if (S[i] == 'p') {
            L = i;
            break;
        }
    }

    string ans = S;
    for (int R = L; R < N; R++) {
        string t = f(S, L, R);
        if (t < ans) ans = t;
    }

    cout << ans << endl;
} 