#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const string ds = "RULD";

int main(){
    string s;
    int t;
    cin >> s >> t;

    pair<int, int> pos = {0, 0};
    int cnt = 0;
    for (char c : s) {
        if (c == '?') cnt++;
        else {
            rep(dir,4) if (ds[dir] == c) {
                pos.first += dx[dir];
                pos.second += dy[dir];
            }
        }
    }

    int ans = abs(pos.first) + abs(pos.second);
    if (t == 1) ans += cnt;
    else {
        if (ans >= cnt) ans -= cnt;
        else ans = (cnt - ans) & 1;
    }
    
    cout << ans << endl;
}