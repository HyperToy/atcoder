#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    map<pair<int, int>, int> mp;
    rep(i,n) rep(j,n) if (i != j) {
        mp[{x[i] - x[j], y[i] - y[j]}]++;
    }
    int mx = 0;
    for (auto p : mp) chmax(mx, p.second);
    cout << n - mx << endl;
} 