#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    set<int> st;
    rep(_,5) {
        int a;
        cin >> a;
        st.insert(a);
    }
    cout << st.size() << endl;
} 