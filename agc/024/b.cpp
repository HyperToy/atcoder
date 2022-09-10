#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}

int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i,N) cin >> P[i], P[i]--;
    vector<int> I(N);
    rep(i,N) I[P[i]] = i;

    int pre = -1;
    int k_max = 0;
    int k = 0;
    rep(i,N) {
        if (I[i] > pre) {
            k++;
        } else {
            chmax(k_max, k);
            k = 1;
        }
        pre = I[i];
    }
    chmax(k_max, k);

    cout << N - k_max << endl;
} 
/*

3 2 5 1 4 6
動かさなくて良い要素を考える
連続とは限らない部分列を抜き出して、
x, x+1, x+2, ..., x+(k-1) を構築する。
残りは適切な順番で、前か後ろに動かせば良いので、操作回数は N - kとなる
操作回数は k が最大の時に最小になる。

k の最大値を求める。
Inverse P の「最大増加連続部分列」の長さを求めれば良い。
P: 3 2  5 1  4 6 
Q: 4 2 (1 5) 3 6
3 4
5 6 も可
*/