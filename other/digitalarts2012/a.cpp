#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string s;
    getline(cin, s);

    int N;
    cin >> N;
    vector<string> t(N);
    rep(i,N) cin >> t[i];
    
    s = " " + s + " ";
    rep(i,N) {
        string reg = " ";
        int l = t[i].length();
        rep(j,l) {
            if (t[i][j] == '*') reg += "[a-z]";
            else reg += t[i][j];
        }
        reg += " ";
        s = regex_replace(s, regex(reg), " " + string(l, '*') + " ");
    }
    s = s.substr(1, s.length() - 2);
    cout << s << endl;
}