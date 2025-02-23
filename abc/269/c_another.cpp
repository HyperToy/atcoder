#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll X;
    cin >> X;

    set<ll> ans;
    // デクリメント：最下位の1を0に変えて、後続をすべて1に変える操作
    for (ll i = (1LL << 60) - 1; i >= 0; i--) {
        i &= X;
        ans.insert(i);
    }

    for (ll i : ans) cout << i << endl;
} 