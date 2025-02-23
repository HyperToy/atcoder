#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i,N) cin >> p[i];
    vector<int> cnt(N, 0);
    rep(i,N) {
        for (int j : {-1, 0, 1}) {
            cnt[(p[i] - i + j + N) % N]++;
        }
    }
    int ans = 0;
    rep(i,N) ans = max(ans, cnt[i]);
    cout << ans << endl;
} 