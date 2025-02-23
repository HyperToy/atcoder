/*
    C - Write and Erase
    2021.07.26
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin >> A.at(i);
    sort(A.begin(), A.end());

    vector<int> dp1(N); // i文字目まで見るときに、数列Aに含まれるA_iの偶奇
    vector<int> dp2(N); // i文字目まで見るときの、答え
    for (int i=0; i<N; i++) {
        if (i == 0) {
            dp1.at(i) = 1;
            dp2.at(i) = 0;
        } else {
            if (A.at(i) == A.at(i-1)) {
                dp1.at(i) = 1 - dp1.at(i-1);
                dp2.at(i) = dp2.at(i-1);
            } else {
                dp1.at(i) = 1;
                dp2.at(i) = dp1.at(i-1) + dp2.at(i-1);
            }
        }
    }
    cout << dp1.at(N-1) + dp2.at(N-1) << endl;
} 