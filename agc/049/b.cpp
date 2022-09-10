#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n) - 1; i >= 0; --i)

int main(){
    int N;
    string S, T;
    cin >> N >> S >> T;
    stack<pair<int, int>> s, t;

    per(i,N) {
        if (s.size() > 0 && S[i] - '0' == s.top().first) s.top().second++;
        else s.emplace(S[i] - '0', 1);
        if (t.size() > 0 && T[i] - '0' == t.top().first) t.top().second++;
        else t.emplace(T[i] - '0', 1);
    }

    int ans = 0;
    rep(_,N) {
        if (s.top().first == t.top().first) {
            s.top().second--; if (s.top().second == 0) s.pop();
            t.top().second--; if (t.top().second == 0) t.pop();
            continue;
        }

        if (s.top().first == 1) {
            if (s.top().second == 1) {
                if (s.size() < 3) {cout << -1 << endl; return 0; }
                stack<pair<int, int>> temp;
                rep(i,3) {temp.push(s.top()); s.pop(); }
                temp.top().second--; 
                if (temp.top().second > 0) s.push(temp.top());
                temp.pop();
                ans += temp.top().second + 1;
                temp.top().second += 2;
                if (s.top().first == temp.top().first) s.top().second += temp.top().second;
                else s.push(temp.top());
                temp.pop();
                temp.pop();
            } else {
                ans += 1;
                s.top().second -= 2;
                if (s.top().second == 0) s.pop();
                if (s.top().first == 0) s.top().second += 2;
                else s.emplace(0, 2);
            }
        } else {
            if (s.size() < 2) {cout << -1 << endl; return 0; }
            stack<pair<int, int>> temp;
            rep(i,2) {temp.push(s.top()); s.pop(); }
            temp.top().second--;
            if (temp.top().second > 0) s.push(temp.top());
            temp.pop();
            ans += temp.top().second;
            if (temp.top().first == s.top().first) s.top().second += temp.top().second;
            else s.push(temp.top());
            temp.pop();
            s.emplace(1,1);
        }

        s.top().second--; if (s.top().second == 0) s.pop();
        t.top().second--; if (t.top().second == 0) t.pop();
    }
    cout << ans << endl;
} 