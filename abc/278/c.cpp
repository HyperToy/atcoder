#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, Q;
    cin >> N >> Q;
    map<int, set<int>> g;
    int T, A, B;
    rep(_,Q) {
        cin >> T >> A >> B;
        A--; B--;
        if (T == 1) {
            g[A].insert(B);
        } else if (T == 2) {
            if (g[A].count(B)) g[A].erase(B);
        } else if (T == 3) {
            if (g[A].count(B) && g[B].count(A)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
