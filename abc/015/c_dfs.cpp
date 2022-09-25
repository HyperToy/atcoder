#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int N, K;
vector<vector<int>> T;

bool dfs(int cnt, int num) {
    if (cnt == N) return num == 0;
    rep(i,K) if (dfs(cnt + 1, num ^ T[cnt][i])) return true;
    return false;
}

int main(){
    cin >> N >> K;
    T = vector(N, vector<int>(K));
    rep(i,N) rep(j,K) cin >> T[i][j];

    if (dfs(0, 0)) cout << "Found" << endl;
    else cout << "Nothing" << endl;
}