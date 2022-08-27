#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353LL;

int main(){
    ll N;
    cin >> N;
    if (N < 0) {
        N += (-N) / MOD * MOD + MOD;
    }
    cout << N % MOD << endl;
} 