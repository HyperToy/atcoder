#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, K;
    cin >> N >> K;
    int a;
    rep(i,N) {
        cin >> a;
        if (i >= K) cout << a << endl;
    }
    rep(_,min(N, K)) cout << 0 << endl;
}
