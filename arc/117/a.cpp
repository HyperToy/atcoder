#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int A, B;
    cin >> A >> B;
    vector<int> E(A + B, 0);
    int s = 0, t = 0;
    rep(i,A) E[i] = i + 1, s += E[i];
    rep(i,B) E[i + A] = -(i + 1), t -= E[i + A];

    if (s > t) {
        int diff = s - t;
        E[A + B - 1] -= diff;
    } else {
        int diff = t - s;
        E[A - 1] += diff;
    }

    rep(i, A + B) cout << E[i] << endl;
}