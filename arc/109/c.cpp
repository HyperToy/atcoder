#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

char winner(char a, char b) {
    if (a == 'R') {
        if (b != 'P') return a;
        else return b;
    }
    if (a == 'P') {
        if (b != 'S') return a;
        else return b;
    }
    if (a == 'S') {
        if (b != 'R') return a;
        else return b;
    }
    return 'X';
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n % 2) (res *= a) %= mod;
        (a *= a) %= mod;
        n /= 2;
    }
    return res;
}

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;

    // dp[i][j] := 2^i 人で、 s の j番目を 番号0 の選手の手とした時の 優勝者の手
    vector<string> dp(k+1, string(n, '.'));
    dp[0] = s;
    int mul = 1;
    for (int i = 1; i <= k; i++) {
        rep(j,n) {
            dp[i][j] = winner(dp[i-1][j], dp[i-1][(j + mul) % n]);
        }
        (mul *= 2) %= n;
    }

    cout << dp[k][0] << endl;
} 