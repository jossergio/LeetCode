impl Solution {
    pub fn minimize_sum(nums: Vec<i32>) -> i32 {
        let mut nums = nums; // Torna mutável
        nums.sort ();
        i32::min (
            nums [nums.len () - 1] - nums [2],
            i32::min (
                nums [nums.len () - 3] - nums [0],
                nums [nums.len () - 2] - nums [1]
            )
        )
    }
}
