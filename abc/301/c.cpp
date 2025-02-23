#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string s, t;
    cin >> s >> t;
    map<char, int> ms, mt;
    set<char> st;
    int sa = 0, ta = 0;
    for (char c : s) {
        st.insert(c);
        if (c == '@') sa++;
        else ms[c]++;
    }
    for (char c : t) {
        st.insert(c);
        if (c == '@') ta++;
        else mt[c]++;
    }
    string atcoder = "atcoder";
    bool ok = true;
    for (char c : st) {
        if (atcoder.find(c) == std::string::npos) {
            if (ms[c] != mt[c]) {
                ok = false;
            }
        } else {
            if (ms[c] > mt[c]) {
                ta-= ms[c] - mt[c];
            } else if (ms[c] < mt[c]) {
                sa-=mt[c]-ms[c];
            }
        }
    }
    if (sa < 0 || ta < 0) {
        ok = false;
    }
    // for (pair<char, int> p : ms) {
    //     char c = p.first;
    //     if (atcoder.find(c) == std::string::npos) {
    //         if (p.second != mt[c]) {
    //             ok = false;
    //         }
    //     } else {
            
    //     }
    // }
    // for (pair<char, int> p : mt) {
    //     char c = p.first;
    //     if (atcoder.find(c) != std::string::npos) {
    //         continue;
    //     }
    //     if (ms[c] < p.second) {
    //         ok = false;
    //     }
    // }
    cout << (ok ? "Yes" : "No") << endl;
}
