#include <bits/stdc++.h>
using namespace std;
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    string S;
    cin >> N >> S;

    if (N == 2) {
        if (S == "AA" || S == "BB") cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }

    if (S[0] == 'A' && S[N-1] == 'B') cout << "No" << endl;
    else cout << "Yes" << endl;
} 