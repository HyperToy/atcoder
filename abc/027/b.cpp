#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    int sum = 0;
    rep(i,N) sum += a[i];
    if (sum % N != 0) {
        cout << -1 << endl;
        return 0;
    }

    int num = sum / N; // 島あたりの人口
    int ans = 0; // 架けた橋の数
    int cnt = 0; // 繋いでいる島の数
    int now = 0; // 繋いでいる島の総人口
    rep(i,N-1) {
        now += a[i];
        cnt++;
        if (now != cnt * num) {
            ans++;
        } else {
            cnt = 0;
            now = 0;
        }
    }

    cout << ans << endl;
    return 0;
}