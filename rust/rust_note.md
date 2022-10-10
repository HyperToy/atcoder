# Rust メモ

## String 方に for (char c : s) みたいなことをする
```rs
// abc081_a
input! {s: String, }
let mut ans: u32 = 0;
for c in s.chars() {
    if c == '1' {
        ans += 1;
    }
}
```
```rs
// abc081_a
input! {s: String, }
let counts: usize = s.chars().filter(|c| c == &'1').count();
```
- &'1' は '1' への参照。 *c == '1' として、参照の中身の値を比較しても通る。

## String を char の配列として受け取る

```rs
use proconio::marker::Chars;
    ...
    input! {
        s: Chars,
    }
```