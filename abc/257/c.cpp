#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;
    vector<int> child, adult;
    for (int i = 0; i < N; i++) {
        int W;
        cin >> W;
        if (S[i] == '0') child.push_back(W);
        else adult.push_back(W);
    }

    int childCnt = child.size();
    int adultCnt = adult.size();

    if (childCnt == 0 || adultCnt == 0) {
        cout << N << endl;
        return;
    }

    sort(child.begin(), child.end());
    sort(adult.begin(), adult.end());

    int ans = 0;
    for (int i = 0; i < adultCnt; i++) {
        int X = adult[i];
        int j = child.end() - lower_bound(child.begin(), child.end(), X);
        int now = N - j - i;
        ans = max(ans, now);
    }

    cout << ans << endl;
}
