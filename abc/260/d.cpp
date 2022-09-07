#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
const int INF = 1001001001;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    rep(i,N) {
        cin >> P[i]; 
        P[i] = -P[i] + 1;
    }

    vector<int> ans(N, -1);
    rep(i,N) {
        if (P[i] == -INF) continue;
        PR(i);
        int last = i;
        set<int> st;
        st.insert(last);
        auto pre = P.begin() + i;
        rep(_,K-1) {
            PR(*pre);
            pre = lower_bound(pre, P.end(), *pre);
            if (pre == P.end()) {
                last = -1;
                break;
            }
            last = pre - P.begin();
            st.insert(last);
            PR(*pre);
        }

        for (int j : st) {
            PR(j);
            if (last != -1) ans[-P[j]] = last + 1;
            P[j] = -INF;
        }
    }
    rep(i,N) cout << ans[i] << endl;
} 