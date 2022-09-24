#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, X;
    cin >> N >> X;
    string str;
    for (int i = 0; i < 26; i++){
        str += string(N, 'A' + i);
    }
    cout << str[X-1] << endl;
}