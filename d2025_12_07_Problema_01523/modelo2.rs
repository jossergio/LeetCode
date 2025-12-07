impl Solution {
    pub fn count_odds(low: i32, high: i32) -> i32 {
        (if high % 2 == 1 { high + 1 } else { high }
        - if low % 2 == 1 { low - 1 } else { low }
        ) / 2
    }
}
