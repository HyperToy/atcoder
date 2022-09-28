#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

bool comp(string &s, string &t) {
    if (s.length() == t.length()) return s < t;
    else return s.length() < t.length();
}

int main(){
    char enc[10];
    rep(i,10) cin >> enc[i];
    char dec[10];
    rep(i,10) dec[enc[i] - '0'] = i + '0';

    int N;
    cin >> N;
    vector<string> a(N);
    rep(i,N) cin >> a[i];

    for (string &s : a) {
        rep(i,s.length()) {
            s[i] = dec[s[i] - '0'];
        }
    }
    sort(a.begin(), a.end(), comp);
    for (string &s : a) {
        rep(i,s.length()) {
            s[i] = enc[s[i] - '0'];
        }
    }

    for (string s : a) {
        cout << s << endl;
    }
}