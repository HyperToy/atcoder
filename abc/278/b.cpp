#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

bool is_confusing(int h, int m) {
    int hh = h / 10 * 10 + m / 10;
    int mm = h % 10 * 10 + m % 10;
    return 0 <= hh && hh < 24 && 0 <= mm && mm < 60;
}

void next_time(int &h, int &m) {
    m++;
    if (m == 60) {
        h++;
        m = 0;
    }
    if (h == 24) {
        h = 0;
    }
}

int main() {
    int H, M;
    cin >> H >> M;
    while (1) {
        if (is_confusing(H, M)) {
            cout << H << endl << M << endl;
            break;
        }
        next_time(H, M);
    }
}
