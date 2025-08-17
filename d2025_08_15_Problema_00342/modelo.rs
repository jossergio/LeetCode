impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        let mut n = n; // Torna mutável
        if n > 0 {
            while n % 4 == 0 {
                n /= 4;
            }
        }
        n == 1
    }
}
