use std::collections::HashSet;
impl Solution {
    pub fn max_sum(nums: Vec<i32>) -> i32 {
        if nums.iter ().any (|v| *v >= 0) {
            return HashSet::<i32>::from_iter::<Vec<i32>> (nums.into_iter ().filter (|v| *v > 0).collect::<_> ()).into_iter ().sum ();
        }
        // else
        nums.into_iter ().filter (|v| *v < 0).max ().unwrap () // Se chegar aqui é porque haverá pelo menos um
    }
}
