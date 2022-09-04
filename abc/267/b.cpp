#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    string S;
    cin >> S;

    if (S[0] == '1') {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<int>> v = {{6}, {3}, {1, 7}, {0, 4}, {2, 8}, {5}, {9}};
    rep(j,7) rep(i,j) {
        bool i_has_stand_pin = false;
        bool j_has_stand_pin = false;
        for (int l : v[i]) if (S[l] == '1') i_has_stand_pin = true;
        for (int l : v[j]) if (S[l] == '1') j_has_stand_pin = true;
        if (! (i_has_stand_pin && j_has_stand_pin)) continue;

        bool exist_collapsed_col = false;
        for (int k = i + 1; k < j; k++) {
            bool k_has_stand_pin = false;
            for (int l : v[k]) {
                if (S[l] == '1') {
                    k_has_stand_pin = true;
                }
            }
            if (! k_has_stand_pin) exist_collapsed_col = true;
        }
        if (exist_collapsed_col) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;
} 