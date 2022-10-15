use proconio::input;

fn main() {
    input! {
        n: usize,
        mut d: [i32; n],
    }
    d.sort();
    let mut ans: u32 = 1;
    for i in 1..n {
        if d[i] != d[i - 1] {
            ans += 1;
        }
    }
    println!("{}", ans);
}
