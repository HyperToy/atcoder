#include <bits/stdc++.h>
using namespace std;

int main(){
    int X, Y, N;
    cin >> X >> Y >> N;
    cout << min(X * N, (N / 3) * Y + (N % 3) * X) << endl;
} 