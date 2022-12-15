use std::cmp;
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        if nums.len ()  == 1 {
            return nums [0]
        }
        let mut nums = Vec::from (nums); // Sombreia, para tornar mutável
        if nums.len () > 2 {
            nums [2] += nums [0]; // Sempre
        }
        for i in 3..nums.len () {
            nums [i] += if nums [i - 2] > nums [i - 3] { nums [i - 2] } else { nums [i - 3] }
        }
        return cmp::max (nums [nums.len () - 2], nums [nums.len () - 1])
    }
}

