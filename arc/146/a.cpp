#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

// 文字列を、数値として昇順に並べ替え
bool comp(string &a, string &b) {
    if (a.length() != b.length()) return a.length() < b.length();
    else return a < b;
}

int main(){
    int N;
    cin >> N;
    vector<string> A(N);
    rep(i,N) cin >> A[i];

    sort(A.rbegin(), A.rend(), comp);
    vector<string> v(3);
    rep(i,3) v[i] = A[i];
    string ans = "0";
    do {
        string s = "";
        rep(i,3) s += v[i];
        if (comp(ans, s)) ans = s;
    } while (next_permutation(v.rbegin(), v.rend(), comp));

    cout << ans << endl;
} 