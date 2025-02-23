#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    cin >> N;

    vector x(N, vector<int>(N));
    int n = 1;
    rep(i,N) rep(j,N) {
        x[i][j] = n++;
    }
    rep(i,N) rep(j,N) {
        if (j % 2 == 1) {
            swap(x[i][j-1], x[i][j]);
        }
    }

    rep(i,N) rep(j,N) {
        cout << x[i][j] << (j == N - 1 ? '\n' : ' ');
    }
} 