#include <bits/stdc++.h>
using namespace std;

int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}
void answer(int x) {
    cout << "! " << x << endl;
}

int main(){
    int N;
    cin >> N;
    vector<int> a;
    int d = N;
    for (int i = 3; i <= N; i++) {
        int x = query(1, i) + query(2, i);
        if (x < d) {
            d = x;
            a.clear();
        }
        if (x == d) {
            a.push_back(i);
        }
    }
    if (d == 3) {
        if (a.size() < 2) {
            d = 1;
        } else {
            if (query(a[0], a[1]) >= 2) {
                d = 1;
            }
        }
    }
    answer(d);
    return 0;
} 