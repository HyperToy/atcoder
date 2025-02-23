#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    sort(A.begin(), A.end());

    int m = 0; // minus
    int p = 0; // plus
    rep(i,N) {
        if (A[i] >= 0) p++;
        else m++;
    }
    if (p == 0) p++, m--;
    if (m == 0) p--, m++;

    vector<pair<int, int>> ans;
    for (int i = m; i < N -1; i++) {
        ans.emplace_back(A[0], A[i]);
        A[0] -= A[i];
    }
    for (int i = 1; i < m; i++) {
        ans.emplace_back(A[N-1], A[i]);
        A[N-1] -= A[i];
    }
    ans.emplace_back(A[N-1], A[0]);
    A[N-1] -= A[0];

    cout << A[N-1] << endl;
    for (auto p : ans) cout << p.first << " " << p.second << endl;
}
/*
それぞれの要素の符号を +, - どちらか選ぶ。
すべて + と すべて - 以外は構築可能
    + の代表と - の代表を選ぶ
    + の代表から - の代表以外を 引き続ける
    - の代表から + の代表以外を 引き続ける
    + の代表から - の代表を引く

オーバーフローチェック
N <= 1e5
Ai <= 1e4
MAX
= 5e4 * 1e4 - 5e4 * (-1e4)
= 5e8 + 5e8
= 1e9 
< INT_MAX
*/