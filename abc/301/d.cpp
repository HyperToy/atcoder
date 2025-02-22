#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string s;
    ll n;
    cin >> s >> n;
    int count = 0;
    for (char c : s) if (c == '?') count++;

    ll ok = -1;
    ll ng = 1LL << count;
    cerr << "(ok, ng): (" << ok << ", " << ng << ")" << endl;
    while (ok + 1 < ng) {
        ll wj = (ok + ng) / 2;
        cerr << "wj: " << wj << endl;
        int pos = 1;
        ll num = 0;
        for (char c : s) {
            num *= 2;
            if (c == '1') num += 1;
            else if (c == '?') {
                num += (wj >> (count - pos))&1LL;
                pos += 1;
            }
        }
        cerr << "num: " << num << endl;
        if (num <= n) ok = wj;
        else ng = wj;
        cerr << "(ok, ng): (" << ok << ", " << ng << ")" << endl;
    }
    cerr << "ok: " << ok << endl;
    if (ok == -1) cout << ok << endl;
    else {
        ll num = 0;
        int pos = 1;
        for (char c : s) {
            num *= 2;
            if (c == '1') num += 1;
            else if (c == '?') {
                num += (ok >> (count - pos))&1LL;
                pos += 1;
            }
            cerr << "num: " << num << endl;
        }
        cout << num << endl;
    }
}
