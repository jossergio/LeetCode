use std::collections::HashSet;
impl Solution {
    pub fn max_sum(nums: Vec<i32>) -> i32 {
        let positivos: HashSet<i32> = HashSet::from_iter (nums.iter ().filter (|&v| *v >= 0).copied ());
        if positivos.len () > 0 {
            return positivos.into_iter ().sum ();
        }
        // else
        nums.into_iter ().filter (|v| *v < 0).max ().unwrap () // Haverá algum, se chegar aqui
    }
}
