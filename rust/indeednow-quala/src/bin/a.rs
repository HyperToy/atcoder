use proconio::*;

fn main() {
    input! {
        a: u32,
        b: u32,
    }
    println!("{}", dig(a) * dig(b));
}

fn dig(mut n: u32) -> u32 {
    let mut res: u32 = 0;
    while n > 0 {
        res += 1;
        n /= 10;
    }
    res
}
