#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int N;
    string S;
    cin >> N >> S;

    int max_serial_p = 0;
    int first_p_pos = -1;
    stack<pair<char, int>> st;
    rep(i,N) {
        if (S[i] == 'p' && first_p_pos == -1) {
            first_p_pos = i;
        }
        if (st.size() > 0 && st.top().first == S[i]) {
            st.top().second++;
        } else {
            st.emplace(S[i], 1);
        }
        if (st.top().first == 'p') {
            max_serial_p = max(max_serial_p, st.top().second);
        }
    }
    int offset = 0;
    stack<int> offsets;
    while (st.size() > 0) {
        if (st.top().first == 'p' && st.top().second == max_serial_p) {
            offsets.push(offset);
            offset = 0;
        }
        offset += st.top().second;
        st.pop();
    }
    if (offsets.size() == 0) {
        cout << S << endl;
        return 0;
    }
    
    vector<string> div;
    div.push_back(S.substr(0, first_p_pos));
    div.push_back(S.substr(first_p_pos, offset - first_p_pos));
    while (offsets.size() > 0) {
        div.push_back(S.substr(offset, offsets.top()));
        offset += offsets.top();
        offsets.pop();
    }
    for (string s : div) PR(s);

    int d = div.size();
    vector<stack<pair<char, int>>> vsp(d);
    rep(i,d) {
        string s = div[i];
        rep(j,s.length()) {
            if (vsp[i].size() > 0 && vsp[i].top().first == s[j]) {
                vsp[i].top().second++;
            } else {
                vsp[i].emplace(s[j], 1);
            }
        }
    }
    set<int> use;
    rep(i,d) {
        if (vsp[i].top().first == 'p') {
            use.insert(i);
        }
    }
    for (int i : use) PR(i);
    while (use.size() > 1) {
        set<int> next_use;
        int max_p_count = 0;
        for (int i : use) {
            if (vsp[i].size() > 0) { 
                max_p_count  = max(max_p_count, vsp[i].top().second);
            }
        }
        for (int i : use) {
            if (vsp[i].size() > 0 && vsp[i].top().second == max_p_count) {
                next_use.insert(i);
                vsp[i].pop();
            }
        }
        use = next_use;
        if (use.size() == 1) break;

        int min_d_count = 1001001001;
        for (int i : use) {
            if (vsp[i].size() > 0) {
                min_d_count = min(min_d_count, vsp[i].top().second);
            }
        }
        for (int i : use) {
            if (vsp[i].size() > 0 && vsp[i].top().second == min_d_count) {
                next_use.insert(i);
                vsp[i].pop();
            }
        }
        use = next_use;
        if (use.size() == 1) break;
    }

    // 1 ~ *(use.begin()) をフリップ
    // int L = first_p_pos;
    int cnt = 0;
    for (int i = 1; i <= *(use.begin()); i++) {
        cnt += div[i].length();
    }
    int L = first_p_pos;
    int R = first_p_pos + cnt;

    for (int i = L, j = R - 1; i < j; i++, j--) {
        swap(S[i], S[j]);
        S[i] = (S[i] == 'd' ? 'p' : 'd');
        S[j] = (S[j] == 'd' ? 'p' : 'd');
    }
    
    cout << S << endl;
} 