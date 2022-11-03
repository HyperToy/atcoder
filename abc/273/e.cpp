#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

struct Node {int value, parent; };

int main(){
    int Q;
    cin >> Q;
    map<int, int> note;
    vector<Node> nodes;

    int now = 0;
    nodes.push_back(Node{-1, 0});

    string s;
    int x;
    while (Q--) {
        cin >> s;
        if (s == "ADD") {
            cin >> x;
            nodes.push_back(Node{x, now});
            now = (int)nodes.size() - 1;
        }
        if (s == "DELETE") {
            now = nodes[now].parent;
        }
        if (s == "SAVE") {
            cin >> x;
            note[x] = now;
        }
        if (s == "LOAD") {
            cin >> x;
            now = note[x];
        }
        cout << nodes[now].value << endl;
    }
}
