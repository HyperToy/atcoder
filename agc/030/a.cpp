#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;
    int ans = 0;
    ans = B + min(A + B + 1 ,C);
    cout << ans << endl;
}