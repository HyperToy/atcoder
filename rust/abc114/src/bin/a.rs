fn main() {
    proconio::input! {
        x: u32,
    }
    if x == 3 || x == 5 || x == 7 {
        println!("YES");
    } else {
        println!("NO");
    }
}
