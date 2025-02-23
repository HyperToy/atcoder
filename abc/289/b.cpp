#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    rep(i,M) cin >> a[i];

    vector<bool> re(N, false);
    rep(i,M) re[a[i] - 1] = true;
    vector<int> ans;
    stack<int> st;
    rep(i,N) {
        if (re[i]) {
            st.push(i);
        } else {
            ans.push_back(i);
            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
        }
    }

    rep(i,N) cout << ans[i] + 1 << endl;
}
