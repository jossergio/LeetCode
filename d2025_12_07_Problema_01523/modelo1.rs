impl Solution {
    pub fn count_odds(low: i32, high: i32) -> i32 {
        (low..(high + 1)).filter (| v | v % 2 == 1).count () as i32
    }
}
