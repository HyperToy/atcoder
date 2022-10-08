#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    vector<set<int>> in(M);
    vector<set<int>> out(M);

    set<int> concerned;
    rep(i,N) {
        // A[i] >= 0 になる
        int j = (-A[i]) / (i + 1);
        if (1 <= j && j <= M) in[j - 1].insert(i);
        if (j < 1) concerned.insert(i);
        // A[i] >= N になる
        j = (N - A[i]) / (i + 1);
        if (1 <= j && j <= M) out[j - 1].insert(i);
    }

    rep(j,M) {
        for (int x : in[j]) concerned.insert(x);

        set<int> block;
        for (int i : concerned) {
            block.insert(A[i] + (i + 1) * (j + 1));
        }
        rep(x,N + 1) if (block.count(x) == 0) {
            cout << x << endl;
            break;
        }

        for (int x : out[j]) concerned.erase(x);
    }
}
