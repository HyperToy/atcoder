#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
const int INF = 1001001001;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    sort(A.begin(), A.end());

    set<int> t;
    rep(i,N-1) {
        if (A[i+1] != A[0]) {
            t.insert(A[i+1] - A[0]);
        }
    }
    if (t.size() == 0) {
        cout << 1 << endl;
        return 0;
    }
    
    int gcd = *(t.begin());
    for (int x : t) {
        gcd = __gcd(gcd, x);
        if (gcd == 1) break;
    }

    int ans = 2;
    if (gcd > 1) ans = 1;
    cout << ans << endl;
} 