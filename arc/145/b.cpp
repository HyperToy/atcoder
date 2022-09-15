#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    ll N, A, B;
    cin >> N >> A >> B;

    ll ans;
    if (A < B) {
        ll lose = min(N, A - 1);
        ans = N - lose;
    } else {
        ll win = (N / A) * B;
        win -= min(N, B - 1);
        win += min(N % A, B - 1);
        ans = win;
    }
    cout << ans << endl;
}