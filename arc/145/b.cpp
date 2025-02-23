#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PR(x) cerr << #x << " = " << x << endl

ll f(ll x, ll a, ll b) {
    return (x / a) * min(a, b) + min(x % a, b - 1);
}

int main(){
    ll N, A, B;
    cin >> N >> A >> B;
    ll ans = max(f(N, A, B) - f(A - 1, A, B), 0LL);
    cout << ans << endl;
}