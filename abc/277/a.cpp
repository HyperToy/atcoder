#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, X;
    cin >> N >> X;
    rep(i,N) {
        int p;
        cin >> p;
        if (p == X) cout << i + 1 << endl;
    }
}
