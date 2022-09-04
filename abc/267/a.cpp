#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string S;
    cin >> S;
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    int ans = -1;
    rep(i,5) {
        if (S == days[i]) {
            ans = 5 - i;
        }
    }
    cout << ans << endl;
} 