impl Solution {
    pub fn sum_zero(n: i32) -> Vec<i32> {
        let mut r: Vec<i32> = Vec::with_capacity (n as usize);
        let m = n / 2;
        if n % 2 == 1 { r.push (0); }
        for v in 1..=m {
            r.extend ([-v, v]);
        }
        r
    }
}
