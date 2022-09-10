#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N, M;
    cin >> N >> M;

    if (N == 1 && M == 0) {
        cout << "1 2" << endl;
        return 0;
    }

    if (M < 0 || M >= N - 1) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> ans(N);
    rep(i,N) {
        ans[i].first = i * 4 + 1;
        ans[i].second = i * 4 + 3;
    }
    if (M > 0) ans[0].second = ans[M+1].second + 1;

    for (auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }
} 
/*
1 3
5 7
9 11
13 15
17 19

-1: 無理 (Takahashi解法 は正しく選ぶ。 Aoki解法 が Takahashi解法 よりも多く選ぶことはあり得ない。)
0: そのまま
1: 1つ目のR を　3つ目のR + 1 の値に変える
2: r1 <- R4 + 1
3: r1 <- r5 + 1
4: 無理 -> N - 1 (Aoki解法 は 最低1は選べる、 Takahashi解法 が N 選ぶ時すべて交わってない, すべて交わってないなら、どちらの解法でも 答えはNになる)
5: 無理

コーナーケース、 (N, M) = (1, 0)
*/