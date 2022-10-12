use proconio::*;

fn main() {
    input! {
        n: usize,
        st: [(String, u32); n],
        x: String,
    }
    let mut sleep: bool = false;
    let mut ans: u32 = 0;
    for i in 0..n {
        if sleep {
            ans += st[i].1;
        }
        if x == st[i].0 {
            sleep = true;
        }
    }
    println!("{}", ans);
}
