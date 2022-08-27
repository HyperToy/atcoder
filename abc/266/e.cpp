#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<double> E(N+1);
    E[1] = 3.5;
    for (int i = 2; i <= N; i++) {
        int cnt = floor(E[i-1]);
        int c = 0;
        for (int j = floor(E[i-1]) + 1; j <= 6; j++) c += j;
        E[i] = (E[i-1] * cnt + c) / 6.0;
    }
    cout << fixed << setprecision(10);
    cout << E[N] << endl;
} 