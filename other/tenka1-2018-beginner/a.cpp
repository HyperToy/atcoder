#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    if (S.length() == 3) reverse(S.begin(), S.end());
    cout << S << endl;
}