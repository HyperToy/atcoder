use proconio::*;

fn main() {
    input! {
        c: char
    }
    println!(
        "{}",
        match c {
            'K' => "Right",
            'L' => "Right",
            'O' => "Right",
            'P' => "Right",
            _ => "Left",
        }
    )
}
