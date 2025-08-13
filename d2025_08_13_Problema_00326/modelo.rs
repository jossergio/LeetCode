impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        let mut n = n; // Torna mutável
        while n % 3 == 0 && n != 0 {
            n /= 3;
        }
        n == 1
    }
}
