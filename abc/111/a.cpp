#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string n;
    cin >> n;
    rep(i,3) {
        n[i] = (n[i] == '1' ? '9' : '1');
    }
    cout << n << endl;
}