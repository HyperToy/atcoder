#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}

int main(){
    int N;
    cin >> N;
    vector<int> c(9);
    rep(i,9) cin >> c[i];

    map<int, int> mp;
    rep(i,9) {
        chmax(mp[c[i]], i + 1);
    }

    pair<int, int> mn = *mp.begin();
    string ans = string(N / mn.first, '0' + mn.second);
    N %= mn.first;

    for (int i = 0; i < ans.length() && N; i++) {
        pair<int, int> mx = mn;
        for (auto p : mp) {
            if (p.first == mn.first) continue;
            if (p.first - mn.first > N) continue;
            if (p.second < mx.second) continue;
            mx = p;
        }
        if (mx.second == mn.second) break;
        ans[i] = mx.second + '0';
        N -= mx.first - mn.first;
    }

    cout << ans << endl;
}