#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int S = 0;
    int n = N;
    while (n) {
        S += n % 10;
        n /= 10;
    }
    cout << (N % S == 0 ? "Yes" : "No") << endl;
}