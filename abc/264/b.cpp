#include <bits/stdc++.h>
using namespace std;

int main(){
    int R, C;
    cin >> R >> C;
    R--, C--;

    R = min(R, 14 - R);
    C = min(C, 14 - C);
    if (R < C) swap(R, C);

    cout << (C % 2 ? "white" : "black") << endl;
}