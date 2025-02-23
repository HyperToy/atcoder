#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> R(N);
    rep(i,N) cin >> R[i];

    double C = 0;
    sort(R.begin(), R.end());
    rep(i,K) {
        C = (C + R[i + N - K]) / 2;
    }

    cout << fixed << setprecision(10);
    cout << C << endl;
}