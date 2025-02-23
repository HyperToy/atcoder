#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i,N) cin >> P[i];

    prev_permutation(P.begin(), P.end());
    rep(i,N) cout << P[i] << endl;
}
