#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, K;
    cin >> N >> K;
    queue<int> a;
    rep(i,N) {
        int x;
        cin >> x;
        a.push(x);
    }
    rep(_,K) {
        a.pop();
        a.push(0);
    }
    while (!a.empty()) {
        cout << a.front() << endl;
        a.pop();
    }
}
