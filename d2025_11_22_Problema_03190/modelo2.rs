impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        nums
            .into_iter ()
            .filter (| v | v % 3 != 0)
            .collect::<Vec<_>> ()
            .len () as i32
    }
}
