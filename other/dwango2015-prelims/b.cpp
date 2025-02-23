#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string S;
    cin >> S;
    int N = S.length();
    vector<pair<int, int>> v;
    
    rep(i,N) {
        if (S[i] == '2' && i + 1 < N && S[i + 1] == '5') {
            i++;
            if (v.size() && v.back().first) v.back().second++;
            else v.emplace_back(1, 1);
        } else {
            if (v.size() && !v.back().first) v.back().second++;
            else v.emplace_back(0, 1);
        }
    }

    ll ans = 0;
    for (auto p : v) {
        if (p.first) {
            ans += (ll)p.second * (p.second + 1) / 2;
        }
    }

    cout << ans << endl;
}