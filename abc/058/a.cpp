#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    bool ok = a + c == b * 2;
    cout << (ok ? "YES" : "NO") << endl;
}