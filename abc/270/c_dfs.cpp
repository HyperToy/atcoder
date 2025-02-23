#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
const int INF = 1001001001;

int main(){
    int N, X, Y;
    cin >> N >> X >> Y;
    X--; Y--;
    vector<vector<int>> g(N);
    rep(i,N-1) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        g[U].push_back(V);
        g[V].push_back(U);
    }
}