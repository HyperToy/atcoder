#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int Q;
    cin >> Q;
    vector<string> s(Q);
    vector<int> a(Q, 0);
    map<int, int> load;
    int del = 0;
    rep(i,Q) {
        cin >> s[i];
        if (s[i] != "DELETE") cin >> a[i];
        else del++;
        if (s[i] == "LOAD") load[a[i]]++;
    }

    deque<int> A;
    map<int, deque<int>> note;
    rep(i,Q) {
        if (s[i] == "ADD") {
            A.push_back(a[i]);
            while (A.size() > del + 1) {
                A.pop_front();
            }
        } else if (s[i] == "DELETE") {
            if (A.size() > 0) A.pop_back();
            del--;
        } else if (s[i] == "SAVE") {
            // map アクセス: O(log|note|)
            // コピー: O(|A|)
            if (load.count(a[i]) && load[a[i]] > 0) {
                note[a[i]] = A;
            }
        } else if (s[i] == "LOAD") {
            // map アクセス: O(log|note|)
            // コピー: O(|note[a[i]]|)
            A = note[a[i]];
            load[a[i]]--;
            // if (load[a[i]] == 0) load.erase(a[i]);
        } else {
            // unreachable!();
        }
        if (A.size() > 0) cout << A.back();
        else cout << -1;
        if (i == Q - 1) cout << endl;
        else cout << " ";
    }
}
