#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i,N) cin >> p[i];
    vector<int> ip(N);
    rep(i,N) ip[p[i]] = i;

    ll sum = 0;
    vector<int> a(N, 0);
    rep(i,N) {
        int k = (ip[i] - i + N) % N;
        if (k < N - k) {
            // minus勢
            a[0]--;
            sum += k;
        } else {
            // plus勢
            a[0]++;
            sum += N - k;
        }
        a[k]+=2;
        a[(k+N/2)%N]--;
        a[(k+(N+1)/2)%N]--;
    }
    rep(j,N-1) a[j+1] += a[j];
    ll ans = sum;
    rep(j,N-1) {
        sum += a[j];
        ans = min(ans, sum);
    }

    cout << ans << endl;
} 