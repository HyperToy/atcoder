#include <bits/stdc++.h>
using namespace std;

// 以下に、24時間表記の時計構造体 Clock を定義する
struct Clock {
    // Clock構造体のメンバ変数を書く
    //   int hour    時間を表す (0~23の値をとる)
    //   int minute  分を表す   (0~59の値をとる)
    //   int second  秒を表す   (0~59の値をとる)
    int hour;
    int minute;
    int second;

    // メンバ関数 set の定義を書く
    //   関数名: set
    //   引数: int h, int m, int s (それぞれ時、分、秒を表す)
    //   返り値: なし
    //   関数の説明:
    //     時・分・秒を表す3つの引数を受け取り、
    //     それぞれ、メンバ変数 hour, minute, second に代入する
    void set(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    // メンバ関数 to_str の定義を書く
    //   関数名: to_str
    //   引数: なし
    //   返り値: string型
    //   関数の仕様:
    //     メンバ変数が表す時刻の文字列を返す
    //     時刻の文字列は次のフォーマット
    //     "HH:MM:SS"
    //     HH、MM、SSはそれぞれ時間、分、秒を2桁で表した文字列
    string to_str() {
        string res;
        if (hour < 10) res += "0";
        res += to_string(hour);
        res += ":";
        if (minute < 10) res += "0";
        res += to_string(minute);
        res += ":";
        if (second < 10) res += "0";
        res += to_string(second);
        return res;
    }

    // メンバ関数 shift の定義を書く
    //   関数名: shift
    //   引数: int diff_second
    //   返り値: なし
    //   関数の仕様:
    //     diff_second 秒だけメンバ変数が表す時刻を変更する(ただし、日付やうるう秒は考えない)
    //     diff_second の値が負の場合、時刻を戻す
    //     diff_second の値が正の場合、時刻を進める
    //     diff_second の値は -86400 ~ 86400 の範囲を取とりうる
    void shift(int diff_second) {
        if (diff_second >= 0) {
            second += diff_second;
            minute += second / 60;
            second %= 60;
            hour += minute / 60;
            minute %= 60;
            hour %= 24;
        } else {
            diff_second *= -1;
            second -= diff_second;
            if (second < 0) {
                int diff_minute = (- second + 60 - 1) / 60;
                second += diff_minute * 60;
                minute -= diff_minute;
            }
            if (minute < 0) {
                int diff_hour = (- minute + 60 - 1) / 60;
                minute += diff_hour * 60;
                hour -= diff_hour;
            }
            if (hour < 0) {
                int diff_day = (- hour + 24 - 1) / 24;
                hour += diff_day * 24;
            }
        }
    }
};

void check(bool x) {
    if (x) cerr << "OK" << endl;
    else cerr << "NG" << endl;
}
void test() {
    Clock clock;
    
    clock.set(0, 0, 0);
    check(clock.to_str() == "00:00:00");

    clock.shift(90);
    check(clock.to_str() == "00:01:30");

    clock.set(0, 0, 40);
    clock.shift(40);
    check(clock.to_str() == "00:01:20");

    clock.set(0, 0, 0);
    clock.shift(-5);
    check(clock.to_str() == "23:59:55");

}

// -------------------
// ここから先は変更しない
// -------------------

void solve() {
    // 入力を受け取る
    int hour, minute, second;
    cin >> hour >> minute >> second;
    int diff_second;
    cin >> diff_second;
        
    // Clock構造体のオブジェクトを宣言
    Clock clock;

    // set関数を呼び出して時刻を設定する
    clock.set(hour, minute, second);

    // 時刻を出力
    cout << clock.to_str() << endl;

    // 時計を進める(戻す)
    clock.shift(diff_second);

    // 変更後の時刻を出力
    cout << clock.to_str() << endl;
}

int main() {
    solve();
    // test();
}