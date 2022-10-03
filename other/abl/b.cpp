#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    bool ok = max(A, C) <= min(B, D);
    cout << (ok ? "Yes" : "No") << endl;
}