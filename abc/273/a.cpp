#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int f(int n) {
    if (n == 0) return 1;
    return n * f(n - 1);
}
int main(){
    int N;
    cin >> N;
    cout << f(N) << endl;
}
