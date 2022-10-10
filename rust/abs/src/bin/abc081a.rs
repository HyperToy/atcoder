use proconio::*;

fn main() {
    input! {
        s: String,
    }
    let mut ans: u32 = 0;
    for c in s.chars() {
        if c == '1' {
            ans += 1;
        }
    }
    println!("{}", ans);
}
