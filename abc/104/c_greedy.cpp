#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 1001001001;
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

int main(){
    int D, G;
    cin >> D >> G;
    vector<int> p(D), c(D);
    rep(i,D) cin >> p[i] >> c[i];

    int ans = INF;
    rep(mask, 1<<D) {
        int now = 0;
        int cnt = 0;
        rep(i,D) {
            if ((mask >> i) & 1) {
                now += (i + 1) * 100 * p[i] + c[i];
                cnt += p[i];
            }
        }
        for (int i = D - 1; i >= 0; i--) {
            if (!((mask >> i) & 1)) {
                for (int j = 0; j < p[i] && now < G; j++) {
                    now += (i + 1) * 100;
                    cnt++;
                }
                break;
            }
        }
        if (now >= G) chmin(ans, cnt);
    }

    cout << ans << endl;
}
