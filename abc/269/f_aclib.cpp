// ac-library の modint を使用

#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
#define PR(x) cerr << #x << " = " << x << endl

ll N, M;
const ll MOD = 998244353LL;

mint f(int a, int b, int c, int d) {
    if (a > b || c > d) return 0;
    if (((b - a) ^ (d - c)) & 1) {
        if ((d - c) & 1) {
            return f(a, b, c, d - 1) + f(a, b, d, d);
        } else {
            return f(a, b - 1, c, d) + f(b, b, c, d);
        }
    }
    mint avg = (mint(a + b) / 2 - 1) * M + mint(c + d) / 2;
    mint cnt = (ll)(b - a + 1) * (d - c + 1) / 2;
    if (!((a + c) & 1) && ((b - a + 1) & 1)) cnt++;
    return avg * cnt;
}

int main(){
    cin >> N >> M;

    int Q;
    cin >> Q;
    while(Q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << f(a, b, c, d).val() << endl;
    }
} 