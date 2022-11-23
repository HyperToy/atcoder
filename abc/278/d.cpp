#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    map<int, ll> minority;
    rep(i,N) cin >> minority[i];
    ll majority = -1;
    int Q;
    cin >> Q;
    int t, i, x;
    rep(_,Q) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            majority = x;
            minority.clear();
        } else if (t == 2) {
            cin >> i >> x;
            i--;
            if (minority.count(i)) minority[i] += x;
            else minority[i] = majority + x;
        } else if (t == 3) {
            cin >> i;
            i--;
            if (minority.count(i)) cout << minority[i] << endl;
            else cout << majority << endl;
        }
    }
}
