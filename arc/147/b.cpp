#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    cin >> N;
    vector<int> P(N), I(N);
    rep(i,N) {
        cin >> P[i];
        P[i]--;
        I[P[i]] = i;
    }

    vector<pair<char, int>> ans;

    vector<stack<int>> st(2);
    rep(i,N) {
        if ((P[i] - i) % 2 != 0) {
            st[i % 2].push(i);
        }
        if (st[0].size() == 0 || st[1].size() == 0) continue;

        int pos0 = st[0].top(); st[0].pop();
        int pos1 = st[1].top(); st[1].pop();
        if (pos0 > pos1) swap(pos0, pos1);
        while (pos0 + 1 != pos1) {
            swap(P[pos0], P[pos0+2]);
            swap(I[P[pos0]], I[P[pos0+2]]);
            ans.emplace_back('B', pos0+1);
            pos0+=2;
        }
        swap(P[pos0], P[pos0+1]);
        swap(I[P[pos0]], I[P[pos0+1]]);
        ans.emplace_back('A', pos0+1);
    }

    for (int i = N-1; i >= 0; i--) {
        while (I[i] != i) {
            int pos = I[i];
            if (pos + 1 == i) {
                // 通らないはず
                swap(P[pos], P[pos+1]);
                swap(I[P[pos]], I[P[pos+1]]);
                ans.emplace_back('A', pos+1);
            } else {
                swap(P[pos], P[pos+2]);
                swap(I[P[pos]], I[P[pos+2]]);
                ans.emplace_back('B', pos+1);
            }
        }
    }

    cout << ans.size() << endl;
    for (auto p : ans) cout << p.first << " " << p.second << endl;
} 