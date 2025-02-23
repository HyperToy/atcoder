#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

map<ll, ll> dp;

ll f(ll n) {
    if (n == 0) return 1;
    if (dp.count(n)) return dp[n];
    ll res = f(n / 2) + f(n / 3);
    return dp[n] = res;
}

int main(){
    ll N;
    cin >> N;
    cout << f(N) << endl;
}
