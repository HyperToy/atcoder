#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    cin >> N;

    set<int> st;
    rep(_,N) {
        int w;
        cin >> w;
        auto iter = st.lower_bound(w);
        if (iter != st.end()) st.erase(iter);
        st.insert(w);
    }

    cout << st.size() << endl;
}