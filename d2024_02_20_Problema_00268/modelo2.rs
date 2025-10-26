use std::collections::HashSet;
impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        *HashSet::<i32>::from_iter ((0..(nums.len () as i32 + 1)).into_iter ()).difference (&HashSet::from_iter (nums.into_iter ())).map (| v | *v).collect::<Vec<_>> ().first ().unwrap ()
    }
}
