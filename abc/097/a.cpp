#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool ok = abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d);
    cout << (ok ? "Yes" : "No") << endl;
}