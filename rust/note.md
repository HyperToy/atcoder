# cargo-atcoder で rust 環境を構築
- [参考](https://qiita.com/maguro_tuna/items/316068eeb8c5b9b31ed8#%E3%83%97%E3%83%AD%E3%82%B8%E3%82%A7%E3%82%AF%E3%83%88%E3%82%92%E4%BD%9C%E6%88%90%E3%81%99%E3%82%8B)
- [github](https://github.com/tanakh/cargo-atcoder)

```sh
$ cargo install cargo-atcoder
$ cargo atcoder login

$ pwd
/Users/nodaryohey/Documents/1_kyoPro/atcoder/rust
$ mkdir ./.cargo
$ echo '[build]\ntarget-dir = "target"' > ./.cargo/config.toml
```
- \n がうまく認識されていないようだったので、エディタで書き換えた。

- 設定ファイルが生成される場所が変だったので、 mv で移動した。
```
$ mv ~/Library/Application\ Support/cargo-atcoder.toml ~/Library/Preferences/cargo-atcoder.toml
```
- github の [issue](https://github.com/tanakh/cargo-atcoder/issues/55) を見た感じ、修正はされているらしく、 README を見ても Preferences のほうになっているので、参照は Preferences だけど、生成が Apprication Suport になってしまっていると解釈した。


- とりあえず、Atcoder Beginners Selection のはじめの問題は通せた。
    - abs のプロジェクトで、 cargo add proconio をやってしまったが、適切に設定ファイルが存在すればいちいち指定しなくてよいものだと思っている。

- 設定ファイルを開いたら、 proconio がコメントアウトされていたので、編集した
    ```sh
    $ code ~/Library/Preferences/cargo-atcoder.toml 
    ```
    - ついでに、テンプレートも少しかえた。

- 1問目も通した（↑は0問目）
    ```sh
    $ cargo atcoder test abc086a
    $ cargo atcoder submit abc086a
    ```
    - if 条件式 {} else {}
    - println! と、エクスクラメーションを忘れない。

- [[Rustで簡単標準入力]proconio使い方まとめ](https://qiita.com/Pikka2048/items/a0247e792aa4f8f6dd92)

- 2問目
    - 文字列を char の配列として扱いたい
    ```rust
    use proconio::marker::Chars;
    ...
        input! {
            s: Chars,
        }
    ```
    - map もつかえたら面白いな。
    - とりあえず、for i in 0..3 {} で通した。
    - cargo に atcoder とつけるのを忘れて、 test は実行できたけど submit なんてコマンドはないよって怒られた。

- とりあえず、ここまでで git commit しておく。
