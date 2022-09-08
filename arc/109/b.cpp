#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve(ll n, ll m) {
    return (n + 1 - m) <= 2 * (n + 1) / (n + 2 - m);
}

int main(){
    ll n;
    cin >> n;

    ll wa = 0;
    ll ac = n+1;
    while (wa + 1 < ac) {
        ll wj = (wa + ac) / 2;
        if (solve(n, wj)) ac = wj;
        else wa = wj;
    }

    cout << ac << endl;
}