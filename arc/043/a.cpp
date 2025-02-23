#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
const int INF = 1001001001;

int main(){
    double N, A, B;
    cin >> N >> A >> B;
    vector<double> S(N);
    rep(i,N) cin >> S[i];

    double mx = 0, mn = INF;
    double sum = 0;
    rep(i,N) {
        mx = max(mx, S[i]);
        mn = min(mn, S[i]);
        sum += S[i];
    }

    if (mx - mn < 1e-6) {
        cout << -1 << endl;
        return 0;
    }

    double P = B / (mx - mn);
    double Q = A - P * sum / N;
    cout << fixed << setprecision(10);
    cout << P << " " << Q << endl;
}