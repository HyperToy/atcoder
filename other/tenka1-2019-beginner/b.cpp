#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, K;
    string S;
    cin >> N >> S >> K;
    K--;
    rep(i,N) if (S[i] != S[K]) S[i] = '*';
    cout << S << endl;
}