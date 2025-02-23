#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string NL;
    getline(cin, NL);
    istringstream iss(NL);
    int N, L;
    iss >> N >> L;
    vector<string> s(L);
    rep(i,L) getline(cin, s[i]);
    string y;
    getline(cin, y);

    int pos = -1;
    rep(i,N) if (y[i * 2] == 'o') pos = i;
    for (int j = L - 1; j >= 0; j--) {
        if (pos > 0 && s[j][pos * 2 - 1] == '-') pos--;
        else if (pos < N - 1 && s[j][pos * 2 + 1] == '-') pos++;
    }

    cout << pos + 1 << endl;
}