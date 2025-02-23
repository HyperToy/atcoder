#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
const int INF = 1001001001;

int ketawa(int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main(){
    int N;
    cin >> N;
    int ans = INF;
    for (int a = 1; a < N; a++) {
        int b = N - a;
        chmin(ans, ketawa(a) + ketawa(b));
    }
    cout << ans << endl;
}