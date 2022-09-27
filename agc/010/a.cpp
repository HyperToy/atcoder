#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    int cnt_odd = 0;
    rep(i,N) if (A[i]&1) cnt_odd++;

    if (cnt_odd % 2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}