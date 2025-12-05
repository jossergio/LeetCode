impl Solution {
    pub fn count_partitions(nums: Vec<i32>) -> i32 {
        if nums
            .iter ()
            .filter (| &v | v % 2 != 0 )
            .count () % 2 == 0 {
                nums.len () as i32 - 1
            } else {
                0
            }
    }
}
