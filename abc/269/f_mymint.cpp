// 自前の modint
// WA が取れない

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PR(x) cerr << #x << " = " << x << endl

long long modpow(long long a, long long n, long long mod = 998244353LL) {
    long long res = 1LL;
    while (n > 0) {
        if (n % 2) (res *= a) %= mod;
        (a *= a) %= mod;
        n /= 2;
    }
    return res;
}

long long moddiv(long long x, long long d, long long mod = 998244353LL) {
    return x % mod * modpow(d, mod - 2, mod) % mod;
}

ll N, M;
const ll MOD = 998244353LL;

ll f(ll a, ll b, ll c, ll d) {
    if (a > b || c > d) return 0;
    if (((b - a) ^ (d - c)) & 1) {
        if ((d - c) & 1) {
            return f(a, b, c, d - 1) + f(a, b, d, d);
        } else {
            return f(a, b - 1, c, d) + f(b, b, c, d);
        }
    }
    ll avg = ((moddiv(a + b, 2) + MOD - 1) % MOD * M % MOD + moddiv(c + d, 2)) % MOD;
    ll cnt = (b - a + 1) * (d - c + 1) / 2;
    if (!((a + c) & 1LL) && ((b - a + 1) & 1LL)) cnt++;
    cnt %= MOD;
    return avg * cnt % MOD;
}

int main(){
    cin >> N >> M;

    int Q;
    cin >> Q;
    while(Q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << f(a, b, c, d) << endl;
    }
} 