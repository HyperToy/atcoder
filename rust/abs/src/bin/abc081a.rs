use proconio::*;
use proconio::marker::*;

fn main() {
    input! {
        s: Chars,
    }
    let mut ans: u32 = 0;
    for i in 0..3 {
        if s[i] == '1' {
            ans += 1;
        }
    }
    println!("{}", ans);
}
