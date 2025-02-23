#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    int mx = 0;
    int ans = -1;
    rep(i,N) {
        int h;
        cin >> h;
        if (h > mx) {
            mx = h;
            ans = i + 1;
        }
    }
    cout << ans << endl;
}
