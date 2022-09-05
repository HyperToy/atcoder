#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

void dfs(vector<int> &v, int &N, int &M) {
    if (v.size() == N) {
        rep(i,N) cout << v[i] << (i == N-1 ? '\n' : ' ');
        return;
    }
    for (int i = 1; i <= M; i++) {
        if (v.size() > 0 && v.back() >= i) continue;
        v.push_back(i);
        dfs(v, N, M);
        v.pop_back();
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> ans;
    dfs(ans, N, M);
} 