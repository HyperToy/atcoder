# Rust メモ

## プロジェクト作成、テスト、提出 [参考](https://github.com/tanakh/cargo-atcoder)
```sh
$ cargo atcoder new <contest-name>
$ cargo atcoder new <contest-name> -b {a..f} # 問題番号が公開されていない場合 --bins も可
$ cargo atcoder test <problem-id>
$ cargo atcoder submit <problem-id>

```

## [proconioまとめ](https://qiita.com/Pikka2048/items/a0247e792aa4f8f6dd92)

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

## 配列の受け取り
```rs
input! {
    n: u8,
    a:[i32;n],
}
println!("{:?}", a);
```
- 配列を変更したいときは、 mut a: [i32;n], とする
- for i in 0..n {} を使うときは、 n: usize, で受け取る

## 入力が分岐する
- 絶対ある分だけ受け取ってから、追加分を受け取る。
- 普通に input!{} で、追加分は受け取れる。深いこと考えなくていい。