#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    sort(a.begin(), a.end());
    deque<ll> q;

    ll rem = 0;
    rep(i,N) {
        if (i > 0 && a[i] == a[i-1]) rem++;
        else q.push_back(a[i]);
    }
    
    ll ans = 0;
    while (!q.empty()) {
        if (q.front() < ans + 1) {
            rem++;
            q.pop_front();
        } else if (q.front() == ans + 1) {
            ans++;
            q.pop_front();
        } else {
            if (rem >= 2) {
                rem -= 2;
                ans++;
            } else if (rem == 1) {
                rem -= 1;
                if (q.size() >= 1) {
                    q.pop_back();
                    ans++;
                } else {
                    break;
                }
            } else {
                if (q.size() >= 2) {
                    q.pop_back();
                    q.pop_back();
                    ans++;
                } else {
                    break;
                }
            }
        }
    }
    ans += rem / 2;
    cout << ans << endl;
}