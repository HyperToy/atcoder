#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int n, m;
    cin >> n >> m;
    vector<bool> ac(n);
    vector<int> wa(n);

    rep(i,m) {
        int p;
        string s;
        cin >> p >> s;
        p--;
        if (s == "AC") {
            ac[p] = true;
        } else {
            if (!ac[p]) {
                wa[p]++;
            }
        }
    }
    int a = 0, w = 0;
    rep(i,n) {
        if (ac[i]) {
            a++;
            w += wa[i];
        } 
    }
    cout << a << endl << w << endl;
} 