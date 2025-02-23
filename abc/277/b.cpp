#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    set<char> suit = {'H', 'D', 'C', 'S'};
    set<char> number = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    int N;
    cin >> N;
    set<string> cards;
    bool ok = true;
    rep(i,N){
        string s;
        cin >> s;
        if (suit.count(s[0]) && number.count(s[1])) {
            cards.insert(s);
        } else {
            ok = false;
        }
    }
    if (ok && cards.size() == N) cout << "Yes" << endl;
    else cout << "No" << endl;
}
