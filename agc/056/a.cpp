#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;

    vector<string> s(N, string(N, '.'));
    int i = 0;
    int j = 0;
    rep(_,N) {
        rep(k,3) {
            s[i][j] = '#';
            (j += 1) %= N;
        }
        i++;
    }

    if (N % 3 != 0) {
        swap(s[0], s[N / 3 - 1]);
        swap(s[N - 1], s[N - N / 3]);
    }

    rep(i,N) cout << s[i] << endl;
}
