use proconio::*;

fn main() {
    input! {
        a: String,
        b: String,
    }
    println!("{}", a.len() * b.len());
}
