#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    int ans = 0;
    rep(i,N) {
        int A;
        cin >> A;
        ans += A;
    }
    cout << ans << endl;
}
