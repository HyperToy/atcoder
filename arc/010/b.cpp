#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

pair<int, int> conv(string s) {
    int pos = -1;
    rep(i,s.length()) if (s[i] == '/') pos = i;
    pair<int, int> res;
    res.first = stoi(s.substr(0,pos));
    res.second = stoi(s.substr(pos+1));
    return res;
}

int day_per_month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dateToNum(int m, int d) {
    m--;
    d--;
    int res = 0;
    rep(i,12) {
        if (i < m) {
            res += day_per_month[i];
        }
    }
    res += d;
    return res;
}

int main(){
    int N;
    cin >> N;

    vector<bool> is_holiday(366, false);
    rep(i,366) {
        if (i % 7 == 0 || i % 7 == 6) {
            is_holiday[i] = true;
        }
    }

    rep(i,N) {
        string s;
        cin >> s;
        pair<int, int> p = conv(s);
        int num = dateToNum(p.first, p.second);
        while (num < 366 && is_holiday[num]) num++;
        if (num < 366) is_holiday[num] = true;
    }

    int ans = 0;
    int now = 0;
    rep(i,366) {
        if (is_holiday[i]) {
            now++;
        } else {
            ans = max(ans, now);
            now = 0;
        }
    }
    ans = max(ans, now);
    cout << ans << endl;
}