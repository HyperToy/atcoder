// TODO: refactor
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    map<ll, ll> mp;
    rep(i,N) mp[A[i]]++;

    vector<ll> groups;
    ll pre = M;
    ll sum = 0;
    bool exist0 = false;
    bool existMax = false;
    for (auto p : mp) {
        if (p.first == 0) exist0 = true;
        if (p.first == M - 1) existMax = true;
        ll now = p.first * p.second;
        sum += now;
        if (p.first == pre + 1) {
            groups.back() += now;
        } else {
            groups.push_back(now);
        }
        pre = p.first;
    }
    if (exist0 && existMax && groups.size() > 1) {
        groups[0] += groups.back();
        groups.pop_back();
    }
    sort(groups.rbegin(), groups.rend());

    cout << sum - groups[0] << endl;
}
