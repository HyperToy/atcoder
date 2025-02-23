#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    set<int> st;
    rep(i,N) {
        while (a[i] % 2 == 0) {
            a[i] /= 2;
        }
        st.insert(a[i]);
    }

    cout << st.size() << endl;
}