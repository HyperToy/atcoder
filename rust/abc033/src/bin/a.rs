use proconio::*;
use proconio::marker::Chars;

fn main() {
    input! {
        s: Chars,
    }
    println!(
        "{}",
        if s[0] == s[1] && s[0] == s[2] && s[0] == s[3] {
            "SAME"
        } else {
            "DIFFERENT"
        }
    )
}
