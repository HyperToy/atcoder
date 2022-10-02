#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;
    int ans;
    if (A == B) ans = C;
    else if (A == C) ans = B;
    else ans = A;
    cout << ans << endl;
}