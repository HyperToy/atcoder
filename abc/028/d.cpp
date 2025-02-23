#include <bits/stdc++.h>
using namespace std;

int main(){
    double N, K;
    cin >> N >> K;

    double p = 0;
    p += 1; // K, K, K
    p += (N - 1) * 3; // K, K, ?(!=K)
    p += (K - 1) * (N - K) * 6; // i < K < j;
    p /= N * N * N;

    cout << fixed << setprecision(15);
    cout << p << endl;
}