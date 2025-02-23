#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    cin >> N;
    string s = "0123456789ABCDEF";
    cout << s[N / 16] << s[N % 16] << endl;
}