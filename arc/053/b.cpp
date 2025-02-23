#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    string S;
    cin >> S;
    int l = S.length();

    vector<int> cnt(26, 0);
    rep(i,l) cnt[S[i] - 'a']++;
    int k = 0;
    rep(i,26) k += cnt[i] % 2;

    int ans;
    if (k > 0) {
        ans = l / k;
        if (ans % 2 == 0) ans--;
    }
    else ans = l;
    cout << ans << endl;
}