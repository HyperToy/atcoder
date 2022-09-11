#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

string ans = "-1";
int N;
vector<string> S;
set<string> T;
vector<bool> used;

void dfs(int k, string x, int depth) {
    if (ans != "-1") return;
    if (depth == 0) {
        rep(i,N) {
            used[i] = true;
            dfs(k, S[i], depth + 1);
            used[i] = false;
        }
        return;
    }
    if (depth == N) {
        if (3 <= x.length() && x.length() <= 16) {
            if (T.count(x) == 0) {
                ans = x;
            }
        }
        return;
    }
    rep(i,N) {
        if (used[i]) continue;
        used[i] = true;
        rep(j,k+1) {
            dfs(k - j, x + string(j+1, '_') + S[i], depth + 1);
        }
        used[i] = false;
    }
}

int main(){
    int M;
    cin >> N >> M;
    S.resize(N);
    rep(i,N) cin >> S[i];
    rep(_,M) {
        string t;
        cin >> t;
        T.insert(t);
    }

    int k = 16 - (N - 1);
    rep(i,N) k -= S[i].length();

    used.resize(N, false);
    dfs(k, "", 0);

    cout << ans << endl;
} 