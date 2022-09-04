#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    deque<int> q;
    ll ans = 0;
    rep(i,N) q.push_back(A[i]);
    sort(q.begin(), q.end());
    while (q.size() > 1) {
        int divisor = q.front();
        int divided = q.back(); q.pop_back();
        if (divided % divisor > 0) {
            q.push_front(divided % divisor);
        }
        ans++;
    }
    
    cout << ans << endl;
} 