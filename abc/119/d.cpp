#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const long long LINF = 1001001001001001001;
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

void push_sort(vector<ll> &s) {
    s.push_back(LINF);
    s.push_back(-LINF);
    sort(s.begin(), s.end());
}
int main(){
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A), rs(A), t(B), rt(B);
    rep(i,A) cin >> s[i], rs[i] = -s[i];
    rep(j,B) cin >> t[j], rt[j] = -t[j];

    push_sort(s);
    push_sort(rs);
    push_sort(t);
    push_sort(rt);

    while (Q--) {
        ll x;
        cin >> x;
        ll ra = *(lower_bound(s.begin(), s.end(), x)) - x;
        ll rb = *(lower_bound(t.begin(), t.end(), x)) - x;
        ll la = *(lower_bound(rs.begin(), rs.end(), -x)) + x;
        ll lb = *(lower_bound(rt.begin(), rt.end(), -x)) + x;

        ll ans = LINF;
        chmin(ans, max(ra, rb));
        chmin(ans, max(la, lb));
        chmin(ans, min(la * 2 + rb, la + rb * 2));
        chmin(ans, min(lb * 2 + ra, lb + ra * 2));
        cout << ans << endl;
    }
}
