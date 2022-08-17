#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "atcoder";
    int L, R;
    cin >> L >> R;
    cout << s.substr(L-1, R - L + 1) << endl;
} 