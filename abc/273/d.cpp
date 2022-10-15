#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int H, W, x, y;
    cin >> H >> W >> x >> y;
    x--; y--;
    map<int, set<int>> rows;
    map<int, set<int>> r_rows;
    map<int, set<int>> cols;
    map<int, set<int>> r_cols;

    int N;
    cin >> N;
    rep(_,N) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        rows[r].insert(c);
        r_rows[r].insert(-c);
        cols[c].insert(r);
        r_cols[c].insert(-r);
    }

    int Q;
    cin >> Q;
    rep(_,Q) {
        char d;
        int l;
        cin >> d >> l;
        if (d == 'D') {
            if (cols.count(y)) {
                cols[y].insert(-1);
                cols[y].insert(H);
                auto iter = cols[y].upper_bound(x);
                x = min(x + l, (*iter) - 1);
            } else {
                x = min(x + l, H - 1);
            }
        } else if (d == 'R') {
            if (rows.count(x)) {
                rows[x].insert(-1);
                rows[x].insert(W);
                auto iter = rows[x].upper_bound(y);
                y = min(y + l, (*iter) - 1);
            } else {
                y = min(y + l, W - 1);
            }
        } else if (d == 'U') {
            if (r_cols.count(y)) {
                r_cols[y].insert(1);
                r_cols[y].insert(-H);
                auto iter = r_cols[y].upper_bound(-x);
                x = max(x - l, -(*iter) + 1);
            } else {
                x = max(x - l, 0);
            }
        } else {
            if (r_rows.count(x)) {
                r_rows[x].insert(1);
                r_rows[x].insert(-W);
                auto iter = r_rows[x].upper_bound(-y);
                y = max(y - l, -(*iter) + 1);
            } else {
                y = max(y - l, 0);
            }
        }
        cout << x + 1 << " " << y + 1 << endl;
    }
}
