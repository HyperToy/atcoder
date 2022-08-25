#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
const int INF = 1001001001;

int question(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}
void answer(int x) {
    cout << "! " << x << endl;
}

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> ps;
    rep(i, N-2) {
        int p = question(1, i+3);
        int q = question(2, i+3);
        ps.emplace_back(p, q);
    }

    // ∀i; d[1,i] = d[2,i] + 1 => d[1,2] = 1
    bool ok1 = true;
    // ∀i; d[1,i] = d[2,i] - 1 => d[1,2] = 1
    bool ok2 = true;
    for (auto p : ps) {
        if (p.first != p.second + 1) {
            ok1 = false;
        }
        if (p.first != p.second - 1) {
            ok2 = false;
        }
    }
    if (ok1 || ok2) {
        answer(1);
        return 0;
    }

    // ∃i; |d[1,i] - d[2,i]| != 1 => d[1,2] = min(d[1,i] + d[2,i])
    bool allDiffOne = true;
    for (auto p : ps) {
        if (abs(p.first - p.second) != 1) {
            allDiffOne = false;
        }
    }
    if (!allDiffOne) {
        int ans = INF;
        for (auto p : ps) {
            chmin(ans, p.first + p.second);
        }
        answer(ans);
        return 0;
    }
    
    // otherwise
    // => ∃i,j; d[1,i] = 1, d[2,i] = 2, d[1,j] = 2, d[2,j] = 1
    // => d[1,2] = 4 - d[i,j];
    int i = -1, j = -1;
    rep(k, N-1) {
        if (ps[k].first == 1 && ps[k].second == 2) {
            i = k + 3;
        }
        if (ps[k].first == 2 && ps[k].second == 1) {
            j = k + 3;
        }
    }
    int ans = 4 - question(i, j);
    answer(ans);
    return 0;
} 