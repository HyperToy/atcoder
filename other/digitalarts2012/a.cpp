#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string s;
    getline(cin, s);
    int n = s.length();

    int N;
    cin >> N;
    vector<string> t(N);
    rep(i,N) cin >> t[i];
    
    for (string u : t) {
        int l = u.length();
        rep(i,n-l+1) {
            bool ok = true;
            rep(j,l) {
                if (s[i+j] == ' ') ok = false;
                if (u[j] != '*' && u[j] != s[i+j]) ok = false;
            }
            if (i != 0 && s[i-1] != ' ') ok = false;
            if (i + l - 1 != n - 1 && s[i + l] != ' ') ok = false;
            if (ok) rep(j,l) s[i+j] = '*';
        }
    }

   cout << s << endl;
}