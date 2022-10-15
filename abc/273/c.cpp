#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    set<int> st;
    vector<int> v;
    rep(i,N) {
        if (!st.count(A[i])) {
            v.push_back(A[i]);
            st.insert(A[i]);
        }
    }
    sort(v.begin(), v.end());
    vector<int> ans(N, 0);
    rep(i,N) {
        auto iter = upper_bound(v.begin(), v.end(), A[i]);
        int cnt = v.end() - iter;
        ans[cnt]++;
    }

    rep(i,N) cout << ans[i] << endl;
}
