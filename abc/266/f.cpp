#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

vector<vector<int>> g;
vector<bool> seen;
int loopStart = -1;
set<int> inLoop;
vector<int> group;

void findLoopDFS(int pos, int pre = -1) {
    seen[pos] = true;

    for (int nxt : g[pos]) {
        if (nxt == pre) continue;
        if (seen[nxt]) {
            loopStart = nxt;
            break;
        }
        findLoopDFS(nxt, pos);
        if (loopStart != -1) break;
    }

    if (loopStart != -1) {
        inLoop.insert(pos);
    }
    if (pos == loopStart) {
        loopStart = -1;
    }
}

void groupingDFS(int pos, int num, int pre = -1) {
    if (seen[pos]) return;
    seen[pos] = true;
    group[pos] = num;
    for (int nxt : g[pos]) {
        if (nxt == pre) continue;
        if (inLoop.count(nxt)) continue;
        groupingDFS(nxt, num, pos);
    }
}

int main(){
    int N;
    cin >> N;
    g.resize(N);
    seen.resize(N, false);
    rep(i,N) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    findLoopDFS(0);

    rep(i,N) seen[i] = false;
    group.resize(N);
    int num = 0;
    for (int i : inLoop) {
        num++;
        groupingDFS(i, num);
    }

    int Q;
    cin >> Q;
    rep(_,Q) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (group[x] == group[y]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
