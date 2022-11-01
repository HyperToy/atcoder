use proconio::*;
use std::collections::HashSet;

fn main() {
    input! {
        n: usize, x: i32, y: i32,
        a: [i32; n],
    }
    let mut even: Vec<i32> = Vec::new();
    let mut odd: Vec<i32> = Vec::new();
    for i in 1..n {
        if i % 2 == 0 {
            even.push(a[i]);
        } else {
            odd.push(a[i]);
        }
    }
    let mut even_dp = HashSet::new();
    even_dp.insert(a[0]);
    let mut odd_dp = HashSet::new();
    odd_dp.insert(0);
    for x in even {
        let mut next_even_dp = HashSet::new();
        for y in even_dp {
            next_even_dp.insert(y + x);
            next_even_dp.insert(y - x);
        }
        even_dp = next_even_dp;
    }
    for x in odd {
        let mut next_odd_dp = HashSet::new();
        for y in odd_dp {
            next_odd_dp.insert(y + x);
            next_odd_dp.insert(y - x);
        }
        odd_dp = next_odd_dp;
    }
    println!(
        "{}",
        if even_dp.contains(&x) && odd_dp.contains(&y) {
            "Yes"
        } else {
            "No"
        }
    )
}
