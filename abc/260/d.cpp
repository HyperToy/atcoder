#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    rep(i,N) cin >> P[i], P[i]--;

    vector<int> under(N, -1); // i の直下にあるカードの数字
    vector<int> pile(N, 0); // i が下から何枚目に積まれたか
    set<int> st; // 上に見えているカードの数字
    vector<int> ans(N, -1);

    rep(i,N) {
        auto itr = st.lower_bound(P[i]);
        if (itr == st.end()) {
            pile[P[i]] = 1;
            st.insert(P[i]);
        } else {
            under[P[i]] = *itr;
            pile[P[i]] = pile[(*itr)] + 1;
            st.erase(itr);
            st.insert(P[i]);
        }

        if (pile[P[i]] == K) {
            st.erase(P[i]);
            int x = P[i];
            rep(_,K) {
                ans[x] = i + 1;
                x = under[x];
            }
        }
    }

    rep(i,N) cout << ans[i] << endl;
} 